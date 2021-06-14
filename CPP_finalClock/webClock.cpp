/*
/*
This was the first project for CS 210 course
I had to develop a "web clock" that would display the time in both 12h and 24h format,
and then had to accept user input to change the time by seconds, minutes, or hours
I opted for a more interactive approach than a simple "menu of items to choose from"
per the instructions. Final result accepts one press of specific keyboard keys to
make changes to times

This is the final version of the app, which uses multiple class files instead of a 
linear design

*/


#include "webClock.h"
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

using namespace std;



webClock webClock::changeTime(webClock newTimer, cursorSet newCursorLoc) {
	
	//change the time of the clock
	
	system("cls");		//clear the screen
	cout << "Current time is: ";
	cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
	cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
	cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;



	webClock tempClock = newTimer;			//save the original time for use later

	bool run = true;
	cout << "Press 'h' to add hours, press 'm' to add minutes, and press 's' to add seconds." << endl;
	cout << "Press 'r' to return to the clock without changes.\n" << endl;


	//draw the clock again for modification

	newCursorLoc.setNewCursor(4, 2);
	cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
	cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
	cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
	while (run) {


		//listen for key presses, adjust time to clock as necessary; redraw the clock each time
		if ((GetAsyncKeyState(0x4D) & 0x01)) {			// 'm' key for 'minutes'
			newTimer.setMinutes(newTimer.getMinutes() + 1);
			newCursorLoc.setNewCursor(4, 2);
			cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
			cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
			cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
		}
		else if ((GetAsyncKeyState(0x53) & 0x01)) {		// 's' key for 'seconds'
			newTimer.setSeconds(newTimer.getSeconds() + 1);
			newCursorLoc.setNewCursor(4, 2);
			cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
			cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
			cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
		}
		else if ((GetAsyncKeyState(0x48) & 0x01)) {		// 'h' key for 'hours'
			newTimer.setHours(newTimer.getHours() + 1);
			newTimer.setMHours(newTimer.getHours());
			newCursorLoc.setNewCursor(4, 2);
			cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
			cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
			cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
		}
		else if ((GetAsyncKeyState(0x52) & 0x01)) {		// 'r' key for 'return' discards changes and returns to clock
			newTimer = tempClock;
			cout << "Discarding changes";
			for (int i = 0; i < 3; i++) {
				Sleep(200);
				cout << ".";
			}
			run = false;
		}
		else if ((GetAsyncKeyState(0x0D) & 0x01)) {		// 'enter' key for 'enter' saves changes and returns to clock
			cout << "Saving changes";
			for (int i = 0; i < 3; i++) {
				Sleep(200);
				cout << ".";
			}
			run = false;
		}

	}

	system("cls");





	return newTimer;
}

