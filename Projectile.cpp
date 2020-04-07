#include "Projectile.h"
#include <graphics.h>
#include <iostream>
Projectile::Projectile(int start_x, int start_y, int vel, int facing) {
	this->d_trav = 0;
	this->start.x_pos = start_x;
	this->start.y_pos = start_y;
	this->current.x_pos = start_x;
	this->current.y_pos = start_y;
	this->velocity = vel;
	this->facing = facing;
	std::cout<<"vel: " << vel << "\n";
}

void Projectile::draw_projectile() {
	circle(this->current.x_pos, this->current.y_pos, 10);
	if(this->velocity == -200 || this->velocity == 200) {
		this->d_trav++;
		this->current.y_pos+=facing*3;
		return;
	}
	this->current.x_pos+=facing*3;
	this->d_trav++;
	this->current.y_pos+=this->velocity*3;
}
