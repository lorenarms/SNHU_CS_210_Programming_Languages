#pragma once

#include <stdio.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "time.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "menus.h"
#include "cursorSet.h"
#include <string>



using namespace std;

class menus
{
public:


	int checkKeyPress();
	void drawMenu(string[], int, int, cursorSet);
	//void drawNewMenu(string[], int, int, cursorSet);




};

