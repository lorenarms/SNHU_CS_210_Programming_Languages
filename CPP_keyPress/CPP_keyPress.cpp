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

