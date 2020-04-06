#ifndef SHIP_H
#define SHIP_H
#include <vector>
#include <graphics.h>

struct Point {
	int x_pos, y_pos;
};

class Ship {
	public:
		int ship_angle;
		int posPtr[8];
		Point ship_origin;
		std::vector<Point> positions;
		std::vector<Point>* get_positions();
		std::vector<Point>* get_tip_tail();
		void rotate_left();
		void rotate_right();
		void rotate();
		void translate(const char &direction);
		void draw_ship();
		void init_start_pos();
		int get_slope();
		void convert_pos();
		Ship();
		~Ship();
};
#endif

