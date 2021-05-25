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