#pragma once
#include "cursorSet.h"
class drawClockFrame
{
public:
	void drawNewClockFrame(int startRow, int startCol, cursorSet newCursorLoc);

	void hideCursorBlink();

	void showMainMenu(cursorSet newCursorLoc);
};

