#include "Menu.h"

/*----- Entry point of program -----*/
int main() {
	Menu menu = Menu();
	menu.show_intro();
	menu.run_default();
	return 0;
}