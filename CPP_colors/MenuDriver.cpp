#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "MenuDriver.h"

using namespace std;

int MenuDriver::CheckKeyPress() {
	if ((GetAsyncKeyState(0x51) & 0x01)) {			// 'q' key for 'quit'
		return 1;
	}
	else if ((GetAsyncKeyState(0x0D) & 0x01)) {		// enter
		return 2;
	}
	else if ((GetAsyncKeyState(0x28) & 0x01)) {		//down arrow
		return 3;
	}
	else if ((GetAsyncKeyState(0x26) & 0x01)) {		//up arrow
		return 4;
	}
	else {									// nada, keep going
		return 0;
	}
}


void MenuDriver::DrawMenu(string items[], int itemsLength, int selection) {
	int selected = 240;
	int unselected = 15;

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);
	
	
	for (int i = 0; i < itemsLength; i++) {
		SetNewCursor(i + 2, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);
		//cout << i << endl;
		
		if (i == selection - 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), selected);
		}
		cout << items[i] << endl;
	}
}
void MenuDriver::DrawMenu(vector<string> menu, int& selection) {
	int selected = 240;
	int unselected = 15;
	for (int i = 0; i < menu.size(); i++) {
		SetNewCursor(i + 2, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);

		if (i == selection - 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), selected);
		}
		cout << menu.at(i) << endl;
		SetNewCursor(6, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);
		//cout << "Index: " << selection << endl;
	}
}

void MenuDriver::RunMenu(vector<string> menu, int& selection) {
	bool i = true;
	int j = 0;
	DrawMenu(menu, selection);
	while (i) {
		j = CheckKeyPress();
		if (j == 3) {				//down
			selection++;
			if (selection > menu.size()) {
				selection = 1;
			}
		}
		else if (j == 4) {		//up
			selection--;
			if (selection < 1) {
				selection = menu.size();
			}
			
		}
		else if (j == 1) {		//quit
			i = false;
			
		}
		else if (j == 2) {		//enter
			return;
		}
		DrawMenu(menu, selection);
	}
}

void MenuDriver::SetNewCursor(int row, int col) {

	//sets cursor position before printing clock
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)col, (SHORT)row };
	SetConsoleCursorPosition(hOut, coord);
}
void MenuDriver::HideCursorBlink() {

	//hide the blinking cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void MenuDriver::MenuModifier(vector<string>& menu) {
	int max = 0;
	int min = 0;
	int spaces = 0;
	string temp = "";
	string space = "";
	for (int i = 0; i < menu.size(); i++) {
		if (menu.at(i).length() > max) {
			max = menu.at(i).length();
			
		}
	}
	max += 10;
	for (int i = 0; i < menu.size(); i++) {
		if (menu.at(i).length() % 2 != 0) {
			menu.at(i) += " ";
		}
		min = max - menu.at(i).length();
		min /= 2;
		for (int j = 0; j < min; j++) {
			space += " ";
		}
		menu.at(i) = space + menu.at(i) + space;
		space = "";

	}
	for (int i = 0; i < menu.size(); i++) {
		if (menu.at(i).length() < max) {
			menu.at(i) + " ";
		}
	}
	
	
}
