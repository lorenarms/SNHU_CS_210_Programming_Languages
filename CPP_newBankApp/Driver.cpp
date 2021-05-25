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
		bool innerRun = true;
		newCalculate.UserInput(newAccount, newMenu, newDraw);
		while (innerRun) {


			innerRun = newCalculate.RunMainProgram(newMenu, newAccount, newDraw);

			
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