#include <iostream>

#include "Calculate.h"
#include "Account.h"
#include "Menu.h"
#include "Draw.h"

using namespace std;

void Calculate::UserInput(Account& newAccount) {
	double x;
	int y;
	
	cout << "Initial investment amount: ";
	cin >> x;
	newAccount.SetInitialInvestment(x);
	cout << "Monthly Deposit: ";
	cin >> x;
	newAccount.SetMonthlyDeposit(x);
	cout << "Interest Rate: ";
	cin >> x;
	newAccount.SetInterestRate(x);
	cout << "Number of years: ";
	cin >> y;
	newAccount.SetNumberOfYears(y);
}




bool Calculate::RunMainProgram(Menu& menu, Account& newAccount) {
	Draw newTable;
	int selection = 0;
	while (selection != 1) {
		selection = menu.CheckKeyPress();
		if (selection == 5) {
			//cout << selection << endl;
			ChangeMonthlyDeposit(menu, newAccount);
			newTable.DrawTable(menu, newAccount);
		}
		if (selection == 6) {
			//cout << selection << endl;
			ChangeInterestRate(menu, newAccount);
			newTable.DrawTable(menu, newAccount);
		}
		
	}
	return false;
	
}

int Calculate::ChangeMonthlyDeposit(Menu& menu, Account& newAccount) {
	bool loop = true;
	int selection = 5;
	while (loop) {
		selection = menu.CheckKeyPress();
		if (selection == 4) {		//up
			newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() + 10);
			system("cls");

		}
		else if (selection == 3) {	//down
			newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() - 10);
			system("cls");

		}
		else if (selection == 5) {	//left
			newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() - 10);
			system("cls");
			return 5;
		}
		else if (selection == 6) {	//right
			newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() - 10);
			system("cls");
			loop = false;
			return 6;
		}

		else if (selection == 1) {
			loop = false;
			return 1;
		}

	}
	//return 5;
}
int Calculate::ChangeInterestRate(Menu& menu, Account& newAccount) {
	int selection;
	selection = menu.CheckKeyPress();
	if (selection == 4) {		//up
		newAccount.SetMonthlyDeposit(newAccount.GetInterestRate() + 0.01);
		system("cls");
		
	}
	else if (selection == 3) {	//down
		newAccount.SetMonthlyDeposit(newAccount.GetInterestRate() - 0.01);
		system("cls");
		
	}
	else if (selection == 5) {	//left
		newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() - 10);
		system("cls");
		return 5;
	}
	else if (selection == 6) {	//right
		newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() - 10);
		system("cls");
		return 6;
	}

	else if (selection == 1) {
		return 1;
	}
	return 6;
}

