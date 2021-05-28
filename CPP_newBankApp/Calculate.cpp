#include <iostream>
#include <conio.h>

#include "Calculate.h"
#include "Account.h"
#include "Menu.h"
#include "Draw.h"

using namespace std;

//most program logic happens in this class

void Calculate::UserInput(Account& newAccount, Menu& newMenu, Draw& newDraw) {	//this function gets all user input
	double x;
	int y;
	newMenu.ShowCursorBlink();
	cin.sync();
	while (_kbhit()) _getch();		//clear keyboard buffer so next input is blank for user
	
	cout << "AirGead Banking: NEW ACCOUNT" << endl;
	cout << setw(86) << setfill('=') << " " << endl;
	cout << setfill(' ');
	
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
												//calculate all values for given number of years, store in vectors/vars
	newAccount.SetNumberOfYears(x);
	x = newAccount.YearsToPages(x);
	newAccount.SetNumberOfPages(x);
	newAccount.SetYearlyBalance();
	system("cls");
	newMenu.HideCursorBlink();
	

}
//Exception handling for invalid inputs
//First checks for doubles
//Second checks that it's not a char or string

double Calculate::InvalidInputHandler() {
	double x;
	cin.clear();				//clears whatever was .cin
	cin.ignore(100, '\n');		//ignores whatever was input up to 100 characters
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

	//this is the main program loop, checks for keyboard input and then redraws the screen accordingly

	int item = 0;		//var for lower menu selection
	int page = 0;		//var for which page you're on
	int data = 0;		//var for displaying months or years (0 = years)
	newMenu.SetNewCursor(15, 0);
	cin.sync();
	while (_kbhit()) _getch();

	int selection = 0;
	//draws the whole page...
	newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);
	
	//check for key presses in CheckKeyPress function
	while (selection != 1) {
		selection = newMenu.CheckKeyPress();
		//check if 'm' is pressed to switch from years to months or back (0 for years)
		if (selection == 8) {
			if (data == 0) {
				data = 1;
				newAccount.SetNumberOfPages(newAccount.SetNumberOfMonthPages());
			}
			else if (data == 1) {
				data = 0;
				system("cls");
				//reset the number of pages to match with years
				newAccount.SetNumberOfPages(newAccount.SetNumberOfYearPages());
			}
			page = 0;		//reset pages to 0 to reduce bugs and drawing issues
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);
		}
		if (selection == 5) {		//left
			//left arrow, page left unless no more pages
			page--;
			if (page < 0) {
				page = 0;
			}
			//highlight left arrows to show user they pressed left
			newMenu.SetNewCursor(15, 21);
			newMenu.SetColor(240);
			cout << "< <";
			newMenu.SetColor(15);
			Sleep(20);
			
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);
		}
		if (selection == 6) {		//right
			//pressed right arrow key
			page++;
			//set pages to last page if max is reached
			//page var is literal, 1 - n, but pages var is for indexes, starts at zero
			if (page > newAccount.GetNumberOfPages() - 1) {
				page = newAccount.GetNumberOfPages() - 1;
			}
			newMenu.SetNewCursor(15, 62);
			newMenu.SetColor(240);
			cout << "> >";
			newMenu.SetColor(15);
			Sleep(20);
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);
			
		}
		if (selection == 3) {	//down arrow
			item++;
			if (item > 4) {		//change item to highlight
				item = 4;
			}
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);
			
		}
		if (selection == 4) {	//up arrow
			item--;
			if (item < 1) {
				item = 1;
			}
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);
			
		}
		if (selection == 2) {	//enter key was pressed
			cin.sync();
			while (_kbhit()) _getch();		//clear the .cin so the last thing entered doesn't show up in the input space
			NewValues(newAccount, item, newDraw, newMenu);	//run NewValues function to get new value, pass item param
			page = 0;	//reset page
			data = 0;	//reset to year display to reduce bug instances, drawing issues
			newDraw.DrawEverything(newMenu, newAccount, page, selection, newDraw, item, data);	//redraw
			newMenu.CheckKeyPress();	//check for new keypress
			
			
		}
		if (selection == 7)		// 'i' key for input
		{
			return 1;	//return back to input menu, reset all values
		}
		if (selection == 0) {
			//do nothing
		}
	}
	return 0;	//return for quit
}

void Calculate::NewValues(Account& newAccount, int item, Draw& newDraw, Menu& newMenu) {
	//changing one item in menu at bottom of page
	//use item param to determine which to change
	switch (item) {
	case 1: {
		int row = 17;
		//call SetNewValues function to change the value, pass row as param to let know where to accept input
		SetNewValues(newMenu, newAccount, item, row, newDraw);
		break;
	}
	case 2: {
		int row = 18;
		SetNewValues(newMenu, newAccount, item, row, newDraw);
		break;
	}
	case 3: {
		int row = 19;
		SetNewValues(newMenu, newAccount, item, row, newDraw);
		break;
	}
	case 4: {
		int row = 20;
		SetNewValues(newMenu, newAccount, item, row, newDraw);
		break;
	}
	default: {

		}
	
	}
	return;
	//return to RunMainProgram to redraw
}

void Calculate::SetNewValues(Menu& newMenu, Account& newAccount, int item, int row, Draw& newDraw) {
	cin.sync();
	while (_kbhit()) _getch();		//clear .cin
	double x;
	newMenu.ShowCursorBlink();
	newMenu.SetNewCursor(row, 25);
	newMenu.SetColor(240);
	printf("%-10s", "");
	newMenu.SetNewCursor(row, 25);
	cin >> x;
	while (cin.fail() || x < 0.00) {	//error checking for correct input
		newMenu.SetNewCursor(row, 35);
		cout << "Invalid input, please try again. ";
		newMenu.SetNewCursor(row, 25);
		x = InvalidInputHandler();
	}
	newMenu.SetColor(15);	//reset the color to standard
	switch (item) {			//switch to see which item to change
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
		if (x < 1) {
			x = 1;
		}
		//these recalculate everything since the number of years determines the amount of pages that should be displayed
		newAccount.SetNumberOfYears(x);
		x = newAccount.YearsToPages(x);
		newAccount.SetNumberOfPages(x);
		//newAccount.SetYearlyBalance();
		break;
	}
	default: {
		break;
	}
	}
	//recalculate the yearly balance for everything
	newAccount.SetYearlyBalance();
	newMenu.HideCursorBlink();
}