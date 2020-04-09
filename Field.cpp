#include <Windows.h>
#include "Field.h"

void Field::handle_inputs() {
	if(GetKeyState('W') & 0x8000) {
		this->ship.translate('w');
	}
	
	if(GetKeyState('A') & 0x8000) {
		this->ship.translate('a');
	}
	
	if(GetKeyState('S') & 0x8000) {
		this->ship.translate('s');
	}
	
	if(GetKeyState('D') & 0x8000) {
		this->ship.translate('d');
	}
	
	if(GetKeyState('Q') & 0x8000) {
		this->ship.rotate_left();
	}
	
	if(GetKeyState('E') & 0x8000) {
		this->ship.rotate_right();
	}
	
	if(GetKeyState('P') & 0x8000) {
		this->add_projectile();
	}
}

void Field::add_projectile() {
	int proj_vel = this->ship.get_slope();
	int facing = this->ship.facing();
	proj_vel *= facing;
	Projectile proj(this->ship.positions.at(1).x_pos, this->ship.positions.at(1).y_pos, proj_vel, facing);
	this->projectiles.push_back(proj);
}

void Field::draw_stuff() {
	//std::cout<<"num projectiles: " << this->projectiles.size() << "\n";
	this->ship.draw_ship();
	auto it = this->projectiles.begin();
	while(it != this->projectiles.end()) {
		if((*it).d_trav >= 300) {
			it = this->projectiles.erase(it);
		} else {
			(*it).draw_body();
			++it;
		}
	}
}

