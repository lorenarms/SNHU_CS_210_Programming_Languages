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
#include "cursorSet.h"
#include "drawClockFrame.h"


using namespace std;


int main()
{	
	//use system time to seed webclock
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int hour = newtime.tm_hour;
	int minute = newtime.tm_min;
	int second = newtime.tm_sec;

	//modify following values to change where the clock displays in the console
	int startRow = 2;
	int startCol = 5;

	//construct a new clock
	webClock newClock(0, 0, 0, 0);	
	newClock.setHours(hour);									
	newClock.setMinutes(minute);
	newClock.setSeconds(second);
	newClock.setMHours(hour);

	//create necessary objects
	clockMenus newMenu;
	drawClockFrame newFrame;
	cursorSet newCursorLoc;
	newFrame.drawNewClockFrame(startRow, startCol, newCursorLoc);
	newFrame.hideCursorBlink();

	int run = 1;

	//menu loop 
	while (run) {

		newFrame.showMainMenu(newCursorLoc);						//draw the title and info
		run = newMenu.checkKeyPress();								//check for key presses
		
		//display the clocks
		newCursorLoc.setNewCursor(startRow + 2, startCol + 12);		

		cout << setw(2) << setfill('0') << newClock.getHours() << ":";
		cout << setw(2) << setfill('0') << newClock.getMinutes() << ":";
		cout << setw(2) << setfill('0') << newClock.getSeconds() << endl;

		newCursorLoc.setNewCursor(startRow + 2, startCol + 50);

		cout << setw(2) << setfill('0') << newClock.getMHours() << ":";
		cout << setw(2) << setfill('0') << newClock.getMinutes() << ":";
		cout << setw(2) << setfill('0') << newClock.getSeconds() << " ";
		cout << newClock.getTOD() << endl;

		newClock.runClock();									//run the clock
		Sleep(1000);											//sleep for one second
		run = newMenu.checkKeyPress();							//check again for key press (makes response more immediate)

		//if '3' is returned, reset to '1' for loop, then go to changeTime to change the time
		if (run == 3) {

			newClock = newClock.changeTime(newClock, newCursorLoc);
			newFrame.drawNewClockFrame(startRow, startCol, newCursorLoc);
			run = 1;
		}
		//quit the program
		else if (run == 0) {
			newCursorLoc.setNewCursor(startRow + 6, startCol);
			cout << "Quitting";					//if quit has been pressed
			for (int i = 0; i < 3; i++) {
				Sleep(200);
				cout << ".";
			}
		}
		else if (run == 4) {
			run = 1;
			newCursorLoc.setNewCursor(startRow + 6, startCol);
			cout << "Program written by Lawrence Artl III" << endl;
			cout << setw(17) << setfill(' ') << right << "May 11, 2021" << endl;
		}

		//continue loop

	}
		
}

