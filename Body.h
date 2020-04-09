#ifndef BODY_H
#define BODY_H
class Body {
	public:
		Point current;
		int facing;
		int velocity;
		int d_trav;
		virtual void draw_body() = 0;
};
#endif
