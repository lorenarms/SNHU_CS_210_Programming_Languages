#include "Menu.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

int Menu::CheckKeyPress() {
	if ((GetAsyncKeyState(0x51) & 0x01)) {			// 'q' key for 'quit'
		return 1;
	}
	else if ((GetAsyncKeyState(0x4D) & 0x01)) {		// 'm' for user input
		return 8;
	}
	else if ((GetAsyncKeyState(0x49) & 0x01)) {		// 'i' for user input
		return 7;
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
	else if ((GetAsyncKeyState(0x25) & 0x01)) {		//left arrow
		return 5;
	}
	else if ((GetAsyncKeyState(0x27) & 0x01)) {		//right arrow
		return 6;
	}
	else {									// nada, keep going
		return 0;
	}
}

//https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

void Menu::SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Menu::DrawMenu(string items[], int itemsLength, int selection) {
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
void Menu::DrawMenu(vector<string> menu, int& selection) {
	int width = menu.at(0).size();
	int column = GetWindowWidth();
	column = column / 2 - (width / 2);
	int selected = 240;
	int unselected = 15;
	for (int i = 0; i < menu.size(); i++) {
		SetNewCursor(i + 12, column);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);

		if (i == selection - 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), selected);
		}
		cout << menu.at(i) << endl;
		SetNewCursor(6, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);
		
	}
}

void Menu::RunMenu(vector<string> menu, int& selection) {
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
			//i = false;
			return;
		}
		DrawMenu(menu, selection);
	}
}

void Menu::SetNewCursor(int row, int col) {

	//sets cursor position before printing clock
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)col, (SHORT)row };
	SetConsoleCursorPosition(hOut, coord);
}
void Menu::HideCursorBlink() {

	//hide the blinking cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Menu::ShowCursorBlink() {

	//hide the blinking cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Menu::MenuModifier(vector<string>& menu) {
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

void Menu::SetWindowSize(int w, int h) {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, w, h, TRUE);
}

int Menu::GetWindowWidth() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return columns;
}
