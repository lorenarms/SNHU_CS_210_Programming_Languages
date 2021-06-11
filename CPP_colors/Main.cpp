#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

#include "MenuDriver.h"

using namespace std;

int MainMenu(MenuDriver& mainMenu, vector<string>& menu, MenuDriver& newCursor, int columnToDraw) {
	int selection = 0;
	bool run = true;
	while (run) {
		mainMenu.RunMenu(menu, selection, columnToDraw);
		switch (selection) {
		case 1:
			system("cls");
			cout << "Selection 1..." << endl;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			system("cls");
			run = false;
			break;
		case 7:
			newCursor.SetNewCursor(10, 0);
			cout << "Continuing..." << endl;
			break;
		default:
			break;
		}
	}


	return selection;
}

int main() {

	//declare your objects
	MenuDriver mainMenu;
	MenuDriver newCursor;
	
	//set your menu items here
	vector <string> menu = { "Selection 1", "Short", "This is long Selection 3" , "this", "new selection", "Quit", "Continue" };
	
	//find the max width of the menu
	int m = mainMenu.MenuModifier(menu);
	//this is to center it; comment out and change to something else to move it
	int w = newCursor.GetWindowWidth();		//also called 'columnToDraw'
	w /= 2;
	w -= (m / 2);
	
	newCursor.HideCursorBlink();

	//variables for loop
	int selection = 0;
	bool run = true;

	MainMenu(mainMenu, menu, newCursor, w);
	
	
	
	return 0;
}

