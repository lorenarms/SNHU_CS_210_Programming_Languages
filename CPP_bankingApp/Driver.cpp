/*
This was my first attempt at developing the "Banking App" for my CS 210 Course, Project 2
i ran into some issues with communication between classes, and had to abandon this project
I eventually figured out it was an issue with circular inclusion, which i fixed in the
updated version "newBankApp"
*/


#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>

#include "Account.h"
#include "Account.h"
#include "Draw.h"
#include "Menu.h"
#include "Calculate.h"

using namespace std;

int main() {
	Account newAccount;
	Menu newMenu;
	Calculate calculator;
	Draw newTable;

	bool run = true;
	
	newMenu.HideCursorBlink();
	calculator.UserInput(newAccount);

	
	system("cls");

	while (run) {
		cout << newAccount.GetMonthlyDeposit() << "     " << newAccount.GetInterestRate() << endl;
		newAccount.SetYearlyBalance();
		newTable.DrawTable(newMenu, newAccount);
		run = calculator.RunMainProgram(newMenu, newAccount);
		newMenu.SetNewCursor(0, 0);


	}

	

}