#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>


using namespace std;

int checkKeyPress() {


	if ((GetAsyncKeyState(0x51) & 0x01)) {
		//cout << "Is false";
		return 0;
	}
	else {
		//cout << "Is true";
		return 1;
	}


}

int main()

{

	int m, s, h;
	bool clock = true;
	char key_press;
	int ascii_value;



	cout << "A COUNTDOWN TIMER " << endl;
	cout << "enter time in hours here" << endl;
	cin >> h;
	cout << "enter time in minutes here " << endl;
	cin >> m;

	cout << "enter im in seconds here" << endl;
	cin >> s;

	cout << "Press any key to start" << endl;

	_getch();
	system("cls");

	cout << " A COUNTDOWN TIMER" << endl;
	cout << "time remaining" << endl;
	cout << "hours : " << h << "mins : " << m << " secs : " << s << endl;
	int loop = 1;
		
	while (loop == 1) {
		
		//these shouldn't be for loops, but instead individual methods
		//so that the while loop can exit when a key is pressed

		for (int hour = h; hour >= 0; hour--)
		{
			if (loop == false) {
				//cout << "false";
				break;
			}
			for (int min = m; min >= 0; min--)
			{
				if (min == 0 && h > 0)
					m = 59;
				if (loop == false) {
					//cout << "false";
					break;
				}
				for (int sec = s; sec >= 0; sec--)
				{
					if (sec == 0)
						s = 59;



					//clock = false;
					clock = checkKeyPress();
					Sleep(1000);

					//clear the screen
					system("cls");

					//sets cursor position before printing clock
					static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					cout.flush();
					COORD coord = { (SHORT)3, (SHORT)3 };
					SetConsoleCursorPosition(hOut, coord);

					cout << hour << ":" << min << ":" << sec << ":" << endl;
					loop = checkKeyPress();
					cout << loop;
					if (loop == false) {
						cout << "false";
						break;
					}


				}
			}
		}
		
		if (loop == false) {
			//cout << "false";
			break;
		}
	}
		
	
	
	Sleep(1000);
	cout << "THE END" << endl;


	return 0;

}

