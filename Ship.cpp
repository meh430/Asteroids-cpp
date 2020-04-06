#include <iostream>
#include <cmath>
#include "Ship.h"

#define PI 3.14159265

Ship::Ship() {
	//set up initial positions
	this->ship_angle = 0;
	this->init_start_pos();
}

Ship::~Ship() {
	//clear device and set position at corner
	for(auto &val : this->positions) {
		val.x_pos = 0;
		val.y_pos = 0;
	}
}

void Ship::init_start_pos() {
	this->ship_origin.x_pos = 0;
	this->ship_origin.y_pos = 15;
	Point lVert;
	lVert.x_pos = 0;
	lVert.y_pos = 0;
	Point rVert;
	rVert.x_pos = 0;
	rVert.y_pos = 30;
	Point tip;
	tip.x_pos = 50;
	tip.y_pos = 15;
	
	this->positions.push_back(lVert);
	this->positions.push_back(tip);
	this->positions.push_back(rVert);
	//{l, tip, r}
}


std::vector<Point>* Ship::get_positions() {
	return &(this->positions);
}

std::vector<Point>* Ship::get_tip_tail() {
	//get tip and the tail
	return nullptr;
}

void Ship::convert_pos() {
	int loc = 0;
	for(auto &val : this->positions) {
		this->posPtr[loc] = val.x_pos;
		++loc;
		this->posPtr[loc] = val.y_pos;
		++loc;
	}
	this->posPtr[loc] = this->positions.at(0).x_pos;
	++loc;
	this->posPtr[loc] = this->positions.at(0).y_pos;
}

double to_rad(int deg) {
	return (deg * PI) / 180;
}

int to_deg(double rad) {
	return (int)round(rad*180 / PI);
}
//{l, tip, r}
void Ship::rotate_left() {
	this->ship_angle+=15;
	if(this->ship_angle > 360) {
		this->ship_angle = this->ship_angle - 360;
	}
	
	this->rotate();
}

void Ship::rotate_right() {
	this->ship_angle-=15;
	if(this->ship_angle < 0) {
		this->ship_angle = 360 + this->ship_angle;
	}
	
	this->rotate();
}

void Ship::rotate() {
	Point main_comp;
	main_comp.x_pos = (int)round(50 * cos(to_rad(this->ship_angle)));
	main_comp.y_pos = (int)round(50 * sin(to_rad(this->ship_angle)));
	Point sub_comp;
	sub_comp.x_pos = (int)round(15 * sin(to_rad(this->ship_angle)));
	sub_comp.y_pos = (int)round(15 * cos(to_rad(this->ship_angle)));
	
	Point *left = &(this->positions.at(0));
	Point *tip = &(this->positions.at(1));
	Point *right = &(this->positions.at(2));
	
	tip->x_pos = this->ship_origin.x_pos + main_comp.x_pos;
	tip->y_pos = this->ship_origin.y_pos - main_comp.y_pos;
	
	left->x_pos = this->ship_origin.x_pos - sub_comp.x_pos;
	left->y_pos = this->ship_origin.y_pos - sub_comp.y_pos;
	
	right->x_pos = this->ship_origin.x_pos + sub_comp.x_pos;
	right->y_pos = this->ship_origin.y_pos + sub_comp.y_pos;
}

void Ship::translate(const char &direction) {
	switch(direction) {
		case 'a':
			//{l, tip, r, tail}
			for(auto &val : this->positions) {
				val.x_pos-=5;
			}
			
			this->ship_origin.x_pos-=5;
			break;
		case 'd':
			for(auto &val : this->positions) {
				val.x_pos+=5;
			}
			
			this->ship_origin.x_pos+=5;
			break;
		case 'w':
			for(auto &val : this->positions) {
				val.y_pos-=5;
			}
			
			this->ship_origin.y_pos-=5;
			break;
		case 's':
			for(auto &val : this->positions) {
				val.y_pos+=5;
			}
			
			this->ship_origin.y_pos+=5;
			break;
	}	
}

void Ship::draw_ship() {
	this->convert_pos();
	fillpoly(3, this->posPtr);
}

int Ship::get_slope() {
	Point tip = this->positions.at(1);
	int d_x = tip.x_pos - this->ship_origin.x_pos;
	int d_y = tip.y_pos - this->ship_origin.y_pos;
	return (int)round(d_y/d_x);
}
