/*
A simple method to check for key presses from the user
this method is used extensively in menus in my other apps

see "finalClock" app or "newBankApp" for more details
*/

using namespace std;
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	cout << "Hello World!\n";

	char GetAsyncKeyState();

	if ((GetAsyncKeyState('q') & 0x8000) < 0) {
		cout << "Is false";
		
	}
	else {
		cout << "Is true";
		
	}
}

