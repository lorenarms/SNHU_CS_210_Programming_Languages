#include <iostream>
#include "cursorSet.h"
#include <Windows.h>
#include <vector>
#include "MenuDriver.h"


using namespace std;

int main() {

	int run = 0;
	int selection = 1;
	MenuDriver newMenu;
	MenuDriver newCursor;
	newCursor.HideCursorBlink();
	vector <string> menu = { "Selection 1", "Short", "This is long Selection 3" , "this", "new selection", "Quit", "Continue" };
	
	newMenu.MenuModifier(menu);
	newMenu.RunMenu(menu, selection);

	//cout << "You selected " << menu.at(selection - 1) << endl;

	

	return 0;
}