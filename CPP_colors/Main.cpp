#include <iostream>
#include "cursorSet.h"
#include <Windows.h>



//#include "stdafx.h"

using namespace std;

int main() {



	/*
	for (int i = 0; i < 256; ++i) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("Text Color in use = %d\n", i);
	}
	*/
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout << "This is some text with a white background.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	cout << "The text has been reset." << endl;

	

	return 0;
}