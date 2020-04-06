#include "Projectile.h"
#include <graphics.h>
Projectile::Projectile(int start_x, int start_y, int vel) {
	this->d_trav = 0;
	this->start.x_pos = start_x;
	this->start.y_pos = start_y;
	this->current.x_pos = start_x;
	this->current.y_pos = start_y;
	this->velocity = vel;
}

void Projectile::draw_projectile() {
	circle(this->current.x_pos, this->current.y_pos, 10);
	this->current.x_pos++;
	this->d_trav++;
	this->current.y_pos+=this->velocity;
}
