#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>

#include "Account.h"
#include "Calculate.h"
#include "Draw.h"
#include "Menu.h"

using namespace std;

int main() {

	Account newAccount;
	Menu newMenu;
	Calculate newCalculate;
	Draw newDraw;

	newMenu.HideCursorBlink();
	
	

	bool outerRun = true;
	

	while (outerRun) {
		system("cls");
		int innerRun = 2;
		newCalculate.UserInput(newAccount, newMenu, newDraw);
		while (innerRun != 1 && innerRun != 0) {


			innerRun = newCalculate.RunMainProgram(newMenu, newAccount, newDraw);
			if (innerRun == 0) {
				outerRun = false;
			}
			else if (innerRun == 1) {
				break;
			}
			
		}
		


	}

	//while loop
		//starts with user input
		//transfers to next loop
		//while loop
			//goes to runmainprogram function
			//if return is false, exit inner loop
			//start again at outer loop

}