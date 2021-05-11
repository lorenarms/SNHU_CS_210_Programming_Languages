#include "drawClockFrame.h"
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


void drawClockFrame::drawNewClockFrame(int startRow, int startCol, cursorSet newCursorLoc) {
	//draws the frame around the clocks
	newCursorLoc.setNewCursor(startRow, startCol);

	cout << setfill('*') << setw(30) << "";
	cout << setfill(' ') << setw(10) << "";
	cout << setfill('*') << setw(30) << "";
	cout << setfill(' ');

	newCursorLoc.setNewCursor(startRow + 1, startCol);
	cout << "*";

	cout << setw(21) << right << "24-HOUR CLOCK" << setw(8) << right << "*";
	cout << setw(10) << "";
	cout << "*";
	cout << setw(21) << right << "12-HOUR CLOCK" << setw(8) << right << "*";


	newCursorLoc.setNewCursor(startRow + 2, startCol);
	cout << "*" << setw(29) << right << "*" << setw(11) << right << "*" << setw(29) << right << "*";


	newCursorLoc.setNewCursor(startRow + 3, startCol);
	cout << setfill('*') << setw(30) << "";
	cout << setfill(' ') << setw(10) << "";
	cout << setfill('*') << setw(30) << "";
}
void drawClockFrame::hideCursorBlink() {
	
	//hide the blinking cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void drawClockFrame::showMainMenu(cursorSet newCursorLoc) {
	
	//title and menu on main clock
	newCursorLoc.setNewCursor(0, 0);
	cout << "Welcome to WebClock. Press 'q' to quit, press 'i' to change the time." << endl;
}

