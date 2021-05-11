#include "clockMenus.h"


int clockMenus::checkKeyPress() {
	if ((GetAsyncKeyState(0x51) & 0x01)) {			// 'q' key for 'quit'
		return 0;
	}
	else if ((GetAsyncKeyState(0x49) & 0x01)) {		// 'i' key for 'info'
		return 3;
	}
	else if ((GetAsyncKeyState(0x4C) & 0x01)) {
		return 4;
	}
	else {									// nada, keep going
		return 1;
	}
}
