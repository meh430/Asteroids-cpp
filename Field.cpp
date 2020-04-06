#include <graphics.h>
#include <Windows.h>
#include "Field.h"

void Field::handle_inputs() {
	if(GetKeyState('W') & 0x8000) {
		this->ship.translate('w');
	} else if(GetKeyState('A') & 0x8000) {
		this->ship.translate('a');
	} else if(GetKeyState('S') & 0x8000) {
		this->ship.translate('s');
	} else if(GetKeyState('D') & 0x8000) {
		this->ship.translate('d');
	} else if(GetKeyState('Q') & 0x8000) {
		this->ship.rotate_left();
	} else if(GetKeyState('E') & 0x8000) {
		this->ship.rotate_right();
	} else if(GetKeyState('P') & 0x8000) {
		this->add_projectile();
	}
}

void Field::add_projectile() {
	Projectile proj(this->ship.positions.at(1).x_pos, this->ship.positions.at(1).y_pos, this->ship.get_slope());
	this->projectiles.push_back(proj);
}

void Field::draw_stuff() {
	this->ship.draw_ship();
	for(auto &val : this->projectiles) {
		if(val.d_trav >= 100) {
			continue;
		}
		val.draw_projectile();
	}
}

