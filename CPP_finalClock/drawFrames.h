#pragma once
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
#include "drawFrames.h"
#pragma once
#include "cursorSet.h"


class drawFrames


{
public:
	void createFrame(int startRow, int startCol, cursorSet newCursorLoc);
};

