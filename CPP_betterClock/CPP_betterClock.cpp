/*
This was the first project for CS 210 course
I had to develop a "web clock" that would display the time in both 12h and 24h format,
and then had to accept user input to change the time by seconds, minutes, or hours
I opted for a more interactive approach than a simple "menu of items to choose from"
per the instructions. Final result accepts one press of specific keyboard keys to 
make changes to times
*/


#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "timer.h"
#include "clock.h"
#include "time.h"
#include <string>

using namespace std;


//	declaring methods bc c++ is so ancient lol
clockk timerMenu(int, int, int);
int checkKeyPress();
void setCursor(int, int);
void createFrame(int, int);
clockk changeTime(clockk);

//	check to see what key is pressed; can be expanded to accomodate new menu items
int checkKeyPress() {


	if ((GetAsyncKeyState(0x51) & 0x01)) {			// 'q' key for 'quit'
		
		return 0;
	}
	else if ((GetAsyncKeyState(0x49) & 0x01)) {		// 'i' key for 'info'
		
		return 3;
	}
	
	else {											// nada, keep going
		
		return 1;
	}


}

//	make a timer; can be called multiple times
clockk timerMenu(int h, int m, int s) {		
	
	clockk newTimer(0, 0, 0, 0);	//construct a new timer
		
	
	
	//timer variables
	//cout << "COUNTDOWN CLOCK " << endl;
	//cout << "Enter a new time in hours: ";
	//cin >> h;
	//cout << "Enter a new time in minutes: ";
	//cin >> m;

	//cout << "Enter a new time in seconds: ";
	//cin >> s;

	newTimer.setHours(h);									//user constructed timer with setters
	newTimer.setMinutes(m);
	newTimer.setSeconds(s);
	newTimer.setMHours(h);


	
	//cout << "***********************" << endl;
	//cout << "Press any key to start..." << endl;			//message to start timer

	/*
	_getch();												//wait for new key press
	system("cls");											//clear screen
	
	
	
	*/
	return newTimer;										//returns timer to loop or main
}


int main()
{
	

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int hour = newtime.tm_hour;
	int minute = newtime.tm_min;
	int second = newtime.tm_sec;

	//cout << setw(2) << setfill('0') << hour << ":";
	//cout << setw(2) << setfill('0') << minute << ":";
	//cout << setw(2) << setfill('0') << second << endl;
	int startRow = 1;
	int startCol = 1;

	
	clockk newTimer = timerMenu(hour, minute, second);							//make a new timer object via the menu
	createFrame(startRow, startCol);
	
	int run = 1;											//loop variable
	while (run == 1) {
		//run = newTimer.checkTime();							//checks to see if time is up
			
		//system("cls");
		
		
		run = checkKeyPress();								//check for key presses

		//display the timer
		
		


		setCursor(startRow + 2, startCol + 12);

		cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
		cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
		cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;

		setCursor(startRow + 2, startCol + 50);

		
		cout << setw(2) << setfill('0') << newTimer.getMHours() << ":";
		cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
		cout << setw(2) << setfill('0') << newTimer.getSeconds() << " ";
		cout << newTimer.getTOD() << endl;

		newTimer.runClock();								//run the timer; subtracts the time
		Sleep(1000);										//sleep for one second
		run = checkKeyPress();								//check again for key press (makes response more immediate)
		
		//if '3' is returned, reset to '1' for loop, then go to timerMenu to change time
		if (run == 3) {
			
			newTimer = changeTime(newTimer);
			createFrame(startRow, startCol);
			run = 1;
		}
		//continue loop
		
		

	}

	if (run == 2) {
		newTimer.timeIsUp();									//display appropriate message
	}
	else if (run == 0) {
		cout << "You ended the timer." << endl;					//if quit has been pressed
	}

	
}

void setCursor(int row, int col) {
	//sets cursor position before printing clock
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)col, (SHORT)row };
	SetConsoleCursorPosition(hOut, coord);
}

void createFrame(int startRow, int startCol) {
	setCursor(startRow, startCol);
	cout << setfill('*') << setw(30) << "";
	cout << setfill(' ') << setw(10) << "";
	cout << setfill('*') << setw(30) << "";
	cout << setfill(' ');

	setCursor(startRow + 1, startCol);
	cout << "*";

	cout << setw(21) << right << "24-HOUR CLOCK" << setw(8) << right << "*";
	cout << setw(10) << "";
	cout << "*";
	cout << setw(21) << right << "12-HOUR CLOCK" << setw(8) << right << "*";


	setCursor(startRow + 2, startCol);
	cout << "*" << setw(29) << right << "*" << setw(11) << right << "*" << setw(29) << right << "*";


	setCursor(startRow + 3, startCol);
	cout << setfill('*') << setw(30) << "";
	cout << setfill(' ') << setw(10) << "";
	cout << setfill('*') << setw(30) << "";

}

clockk changeTime(clockk newTimer) {

	system("cls");
	cout << "Current time is: ";
	cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
	cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
	cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;

	clockk tempClock = newTimer;
	bool run = true;
	cout << "Press 'h' to add hours, press 'm' to add minutes, and press 's' to add seconds." << endl;
	cout << "Press 'r' to return to the clock without changes.\n" << endl;
	setCursor(4, 0);
	cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
	cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
	cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
	while (run) {
		
		
		
		if ((GetAsyncKeyState(0x4D) & 0x01)) {			// 'm' key for 'minutes'
			newTimer.setMinutes(newTimer.getMinutes() + 1);
			setCursor(4, 0);
			cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
			cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
			cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
		}
		else if ((GetAsyncKeyState(0x53) & 0x01)) {		// 's' key for 'seconds'
			newTimer.setSeconds(newTimer.getSeconds() + 1);
			setCursor(4, 0);
			cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
			cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
			cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
		}
		else if ((GetAsyncKeyState(0x48) & 0x01)) {		// 'h' key for 'hours'
			newTimer.setHours(newTimer.getHours() + 1);
			newTimer.setMHours(newTimer.getHours());
			setCursor(4, 0);
			cout << setw(2) << setfill('0') << newTimer.getHours() << ":";
			cout << setw(2) << setfill('0') << newTimer.getMinutes() << ":";
			cout << setw(2) << setfill('0') << newTimer.getSeconds() << endl;
		}
		else if ((GetAsyncKeyState(0x52) & 0x01)) {		// 'r' key for 'return'
			newTimer = tempClock;
			run = false;
		}
		else if ((GetAsyncKeyState(0x0D) & 0x01)) {		// 'enter' key for 'enter'
					
			run = false;
		}

	}
	
	system("cls");
	
	



	return newTimer;
}


