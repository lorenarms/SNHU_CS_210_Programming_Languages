#pragma once

#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "time.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class MenuDriver
{
public:

	int CheckKeyPress();
	void DrawMenu(vector<string>, int&, int&);
	void SetNewCursor(int row, int col);
	void HideCursorBlink();
	void ShowCursorBlink();
	void RunMenu(vector<string>, int&, int&);
	int MenuModifier(vector<string>& menu);
	void SetWindowSize(int w, int h);
	int GetWindowWidth();
	void SetColor(int color);

};

