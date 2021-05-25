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
	//while ((getchar()) != '\n');
	cin.sync();
	while (_kbhit()) _getch();				//clear keyboard buffer so next input is blank for user
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
	newAccount.SetYearlyBalance();
	system("cls");
	//newAccount.SetPages();

}

bool Calculate::RunMainProgram(Menu& newMenu, Account& newAccount, Draw& newDraw) {
	int item = 1;
	int page = 0;
	newMenu.SetNewCursor(15, 0);
	cout << "Page " << page << " of " << newAccount.GetNumberOfPages() << endl;
	

	int selection = 0;
	
	while (selection != 1) {
		selection = newMenu.CheckKeyPress();
		
		if (selection == 5) {		//left
			system("cls");
			page--;
			if (page < 0) {
				page = 0;
			}
		}
		if (selection == 6) {		//right
			system("cls");
			page++;
			if (page > newAccount.GetNumberOfPages() - 1) {
				page = newAccount.GetNumberOfPages() - 1;
			}
			
		}
		if (selection == 3) {
			item++;
			if (item > 4) {
				item = 4;
			}
			
		}
		if (selection == 4) {
			item--;
			if (item < 1) {
				item = 1;
			}
			
		}
		if (selection == 7)		// 'm' key for input
		{
			return 1;
		}
		newMenu.SetNewCursor(15, 0);
		cout << "Page " << page + 1 << " of " << newAccount.GetNumberOfPages() << endl;
		newMenu.SetNewCursor(16, 0);
		cout << "Menu item: " << item << endl;
		newMenu.SetNewCursor(0, 0);
		newAccount.GetPages(page);
		
	}
	
	return 0;

}