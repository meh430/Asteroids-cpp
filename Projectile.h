#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Ship.h"
#include "Body.h"
class Projectile : public Body {
	public:
		Point start;
		Projectile(int start_x, int start_y, int vel, int facing);
		void draw_body();
};
#endif
