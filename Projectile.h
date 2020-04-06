#ifndef PROJECTILE_H
#define PROJECTILE_H
class Projectile {
	public:
		Point start;
		Point current;
		int velocity;
		int d_trav;
		void draw_projectile();
		Projectile(int start_x, int start_y, int vel);
};
#endif
