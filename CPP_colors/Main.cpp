#include <iostream>
#include "cursorSet.h"
#include <Windows.h>
#include <vector>
#include "MenuDriver.h"


using namespace std;

int mainMenu(MenuDriver& newMenu);

int main() {

	int run = 0;
	bool mainPrgm = true;
	
	MenuDriver newMenu;
	MenuDriver newCursor;
	newCursor.HideCursorBlink();
	while (mainPrgm) {
		run = mainMenu(newMenu);
		if (run == 6) {
			mainPrgm = false;
		}
		else if (run == 7) {
			newCursor.SetNewCursor(10, 10);
			cout << "Continuing..." << endl;
			
		}

	}

	//cout << "You selected " << menu.at(selection - 1) << endl;
	return 0;
}

int mainMenu(MenuDriver& newMenu) {
	int selection = 0;
	vector <string> menu = { "Selection 1", "Short", "This is long Selection 3" , "this", "new selection", "Quit", "Continue" };

	newMenu.MenuModifier(menu);
	newMenu.RunMenu(menu, selection);
	return selection;
}