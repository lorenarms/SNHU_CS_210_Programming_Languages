#include <iostream>
#include "cursorSet.h"
#include <Windows.h>
#include "menus.h"




//#include "stdafx.h"

using namespace std;

int main() {



	/*
	for (int i = 0; i < 256; ++i) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("Text Color in use = %d\n", i);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "This is some text with a white background.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << endl;
		cout << "The text has been reset." << endl;
	}
	*/
	

	int run = 0;
	int selection = 1;
	cursorSet newCursor;
	newCursor.hideCursorBlink();
	menus newMenu;
	string menu[4] = { "Selection 1", "Selection 2", "Selection 3" , "Selection 4"};
	int menuList = 4;


	while (run != 1) {
		newMenu.drawMenu(menu, menuList, selection, newCursor);

		
		
		
		run = newMenu.checkKeyPress();
		if (run == 3) {
			selection++;
			if (selection > menuList) {
				selection = 1;
			}
		}
		else if (run == 4) {
			selection--;
			if (selection < 1) {
				selection = menuList;
			}
		}
				

	}

	

	

	return 0;
}