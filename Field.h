#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include "Ship.h"
#include "Projectile.h"
class Field {
	public:
		Ship ship;
		std::vector<Projectile> projectiles;
		void handle_inputs();
		void draw_stuff();
		void add_projectile();
};
#endif
