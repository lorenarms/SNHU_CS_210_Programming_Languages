#include "cursorSet.h"
#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "time.h"
#include <string>
#include <iomanip>
#include <iostream>


using namespace std;




void cursorSet::setNewCursor(int row, int col) {
	
	//sets cursor position before printing clock
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)col, (SHORT)row };
	SetConsoleCursorPosition(hOut, coord);
}
void cursorSet::hideCursorBlink() {

	//hide the blinking cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
