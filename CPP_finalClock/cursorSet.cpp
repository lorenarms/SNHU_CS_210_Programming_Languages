#include "cursorSet.h"
#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "time.h"
#include <string>
#include "webClock.h"
#include <iomanip>
#include <iostream>
#include "clockMenus.h"


void cursorSet::setNewCursor(int row, int col) {
	
	//sets cursor position before printing clock
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)col, (SHORT)row };
	SetConsoleCursorPosition(hOut, coord);
}
