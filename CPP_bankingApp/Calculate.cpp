#include <iostream>

#include "Calculate.h"
#include "Account.h"
#include "Menu.h"

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
	int selection;
	selection = menu.CheckKeyPress();
	if (selection == 4) {
		newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() + 10);
		system("cls");
		return true;
	}
	else if (selection == 3) {
		newAccount.SetMonthlyDeposit(newAccount.GetMonthlyDeposit() - 10);
		system("cls");
		return true;
	}

	else if (selection == 1) {
		return false;
	}
	return true;
}
