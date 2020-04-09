#ifndef ASTEROID_H
#define ASTEROID_H
#include "Ship.h"
#include "Body.h"
class Asteroid : public Body {
	public:
		int size;
		void draw_body();
		Asteroid(int x, int y, int size, int velocity, int facing);
		
};
#endif
