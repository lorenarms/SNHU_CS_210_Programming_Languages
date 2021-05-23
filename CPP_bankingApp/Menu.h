#pragma once

#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Menu
{
public:


	int CheckKeyPress();
	void DrawMenu(string[], int, int);
	void DrawMenu(vector<string>, int&);
	void SetNewCursor(int row, int col);
	void HideCursorBlink();
	void RunMenu(vector<string>, int&);
	void MenuModifier(vector<string>& menu);
	void SetWindowSize(int w, int h);



};

