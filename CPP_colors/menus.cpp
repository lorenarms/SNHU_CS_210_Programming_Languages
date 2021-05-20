#include "menus.h"
#include "cursorSet.h"


int menus::checkKeyPress() {
	if ((GetAsyncKeyState(0x51) & 0x01)) {			// 'q' key for 'quit'
		return 1;
	}
	else if ((GetAsyncKeyState(0x0D) & 0x01)) {		// enter
		return 2;
	}
	else if ((GetAsyncKeyState(0x28) & 0x01)) {		//down arrow
		return 3;
	}
	else if ((GetAsyncKeyState(0x26) & 0x01)) {		//up arrow
		return 4;
	}
	else {									// nada, keep going
		return 0;
	}
}


void menus::drawMenu(string items[], int itemsLength, int selection, cursorSet newCursor) {
	int selected = 240;
	int unselected = 15;

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);
	
	
	for (int i = 0; i < itemsLength; i++) {
		newCursor.setNewCursor(i + 2, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), unselected);
		//cout << i << endl;
		
		if (i == selection - 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), selected);
		}
		cout << items[i] << endl;
	}
	
	

}
