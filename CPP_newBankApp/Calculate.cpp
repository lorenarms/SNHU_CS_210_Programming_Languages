#include <iostream>
#include <conio.h>

#include "Calculate.h"
#include "Account.h"
#include "Menu.h"
#include "Draw.h"

using namespace std;

void Calculate::UserInput(Account& newAccount, Menu& newMenu, Draw& newDraw) {
	double x;
	int y;
	
	cin.sync();
	while (_kbhit()) _getch();		//clear keyboard buffer so next input is blank for user
	
	
	cout << "Initial investment amount: ";
	cin >> x;
	while (cin.fail() || x < 0.01) {
		cout << "Invalid input; please enter a number greater than zero: ";
		x = InvalidInputHandler();
	}
	newAccount.SetInitialInvestment(x);
	cout << "Monthly Deposit: ";
	cin >> x;
	while (cin.fail() || x < 0) {
		cout << "Invalid input; please enter a number ('0' for no deposit): ";
		x = InvalidInputHandler();
	}
	newAccount.SetMonthlyDeposit(x);
	cout << "Interest Rate: ";
	cin >> x;
	while (cin.fail() || x < .01 || x > 100) {
		cout << "Invalid input; please enter a number between 0.01 and 100: ";
		x = InvalidInputHandler();
	}
	newAccount.SetInterestRate(x);
	cout << "Number of years: ";
	cin >> x;
	while (cin.fail() || x < 1) {
		cout << "Invalid input; please enter a number greater than zero: ";
		x = InvalidInputHandler();
	}
	newAccount.SetNumberOfYears(x);
	newAccount.SetYearlyBalance();
	system("cls");
	

}
double Calculate::InvalidInputHandler() {
	double x;
	cin.clear();
	cin.ignore(100, '\n');
	//cout << "Invalid input; please enter a number: ";
	cin >> x;
	return x;
}
double Calculate::LessThanRequiredInputHandler() {
	double x;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Input must be greater than 0: ";
	cin >> x;
	return x;
}

bool Calculate::RunMainProgram(Menu& newMenu, Account& newAccount, Draw& newDraw) {
	int item = 0;
	int page = 0;
	newMenu.SetNewCursor(15, 0);
	cin.sync();
	while (_kbhit()) _getch();

	int selection = 0;
	newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item);
	
	
	while (selection != 1) {
		selection = newMenu.CheckKeyPress();
		
		if (selection == 5) {		//left
			
			page--;
			if (page < 0) {
				page = 0;
			}
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item);
		}
		if (selection == 6) {		//right
			
			page++;
			if (page > newAccount.GetNumberOfPages() - 1) {
				page = newAccount.GetNumberOfPages() - 1;
			}
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item);
			
		}
		if (selection == 3) {
			item++;
			if (item > 4) {
				item = 4;
			}
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item);
			
		}
		if (selection == 4) {
			item--;
			if (item < 1) {
				item = 1;
			}
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item);
			
		}
		if (selection == 2) {
			cin.sync();
			while (_kbhit()) _getch();
			NewValues(newAccount, item, newDraw, newMenu);
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item);
			newMenu.CheckKeyPress();
			
			
		}
		if (selection == 7)		// 'm' key for input
		{
			return 1;
		}
		if (selection == 0) {

		}

		
		
	}
	
	return 0;

}

void Calculate::NewValues(Account& newAccount, int item, Draw& newDraw, Menu& newMenu) {
	switch (item) {
	case 1: {
		int row = 17;
		SetNewValues(newMenu, newAccount, item, row);
		break;
	}
	case 2: {
		int row = 18;
		SetNewValues(newMenu, newAccount, item, row);
		break;
	}
	case 3: {
		int row = 19;
		SetNewValues(newMenu, newAccount, item, row);
		break;
	}
	case 4: {
		int row = 20;
		SetNewValues(newMenu, newAccount, item, row);
		break;
	}
	default: {

		}
	//cin.sync();
	//while (_kbhit()) _getch();
	}
	return;
}

void Calculate::SetNewValues(Menu& newMenu, Account& newAccount, int item, int row) {
	cin.sync();
	while (_kbhit()) _getch();
	double x;
	newMenu.ShowCursorBlink();
	newMenu.SetNewCursor(row, 25);
	newMenu.SetColor(240);
	printf("%-10s", "");
	newMenu.SetNewCursor(row, 25);
	cin >> x;
	newMenu.SetColor(15);
	switch (item) {
	case 1: {
		newAccount.SetInitialInvestment(x);
		break;
	}
	case 2: {
		newAccount.SetMonthlyDeposit(x);
		break;
	}
	case 3: {
		newAccount.SetInterestRate(x);
		break;
	}
	case 4: {
		newAccount.SetNumberOfYears(x);
		break;
	}
	default: {
		break;
	}
	}
	newAccount.SetYearlyBalance();
	newMenu.HideCursorBlink();
}