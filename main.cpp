#include <graphics.h>
#include "Field.h"
int main() {
	initwindow(800, 800);
	Field field;
	
	while(true) {
		field.handle_inputs();
		cleardevice();
		field.draw_stuff();
		delay(17);
	}
}

