﻿#include "Calculate.h"
#include "Account.h"
#include "Menu.h"
#include "Draw.h"

#include <string>



//this function is old, no longer used
void Draw::DrawTable(Menu& menu, Account& newAccount, int page) {

	printf("%-10s%-10s%-16s%-10s\n", "Year", "Deposit", "Interest", "Balance");
	for (int i = 0; i < newAccount.GetNumberOfYears(); i++) {
		printf("%-10d", i + 1);
		printf("%-10.2f", newAccount.GetMonthlyDeposit());
		printf("% 1s", "$");
		printf("%-15.2f", newAccount.GetYearlyInterestEarned(i));
		printf("% 1s", "$");
		printf("%-10.2f", newAccount.GetYearlyBalance(i));
		cout << endl;
	}
}

//this function draws the pages for the years
//it was written first, the next function was a carbon copy 
//this was easier than trying to write a function as long as both combined that took in endless
//params and checked for months versus years
//a project for another time

void Draw::DrawPages(Account& newAccount, int minEntry, int maxEntry) {
	//this function gets called from the Account file, from GetPages()
	//draw the header
	cout << " AirGead Banking: Account Statistics" << endl;
	cout << setw(86) << setfill('=') << " " << endl;
	cout << setfill(' ');
	cout << right << setw(5) << "Year" << setw(25) << "Monthly Deposit" << setw(25) << "Interest Earned" << setw(30) << "Year-end Balance" << endl;
	cout << setw(86) << setfill('-') << " " << endl;
	cout << setfill(' ');
	string output;
	//draw all the items through a loop
	//min and max entry vars let it know when to stop
	for (int i = minEntry; i < maxEntry; i++) {
		cout << fixed << right << setw(5) << i + 1;
		output = "$" + to_string(newAccount.GetMonthlyDeposit());
		size_t pos = output.find(".");
		output = output.substr(0, pos + 3);
		cout << fixed << setprecision(2) << setw(25) << right << output;
		output = "$" + to_string(newAccount.GetYearlyInterestEarned(i));
		pos = output.find(".");
		output = output.substr(0, pos + 3);
		cout << fixed << setw(25) << right << output;
		output = "$" + to_string(newAccount.GetYearlyBalance(i));
		pos = output.find(".");
		output = output.substr(0, pos + 3);
		cout << fixed << setw(30) << right << output;
		cout << endl;
		cout << endl;
		
	}

}
//this is the same function as above
//gets called from Account, GetMonthPages()
void Draw::DrawMonthPages(Account& newAccount, int minEntry, int maxEntry) {

	cout << " AirGead Banking: Account Statistics" << endl;
	cout << setw(86) << setfill('=') << " " << endl;
	cout << setfill(' ');
	cout << right << setw(5) << "Month" << setw(25) << "Monthly Deposit" << setw(25) << "Interest Earned" << setw(30) << "Month-end Balance" << endl;
	cout << setw(86) << setfill('-') << " " << endl;
	cout << setfill(' ');
	string output;
	for (int i = minEntry; i < maxEntry; i++) {
		cout << fixed << right << setw(5) << i + 1;
		output = "$" + to_string(newAccount.GetMonthlyDeposit());
		size_t pos = output.find(".");
		output = output.substr(0, pos + 3);
		cout << fixed << setprecision(2) << setw(25) << right << output;
		output = "$" + to_string(newAccount.GetMonthlyInterestEarned(i));
		pos = output.find(".");
		output = output.substr(0, pos + 3);
		cout << fixed << setw(25) << right << output;
		output = "$" + to_string(newAccount.GetMonthlyBalance(i));
		pos = output.find(".");
		output = output.substr(0, pos + 3);
		cout << fixed << setw(30) << right << output;
		cout << endl;
		cout << endl;

	}

}
//this function draws the menu at the bottom of the main page
void Draw::DrawMenu(Account& newAccount, Menu& newMenu, int item) {
	//draw the menu at the bottom
	newMenu.SetNewCursor(17, 0);
	printf("%25s%-10.2f\n", "Initial Investment: ", newAccount.GetInitialInvestment());
	printf("%25s%-10.2f\n", "Monthly Deposit: ", newAccount.GetMonthlyDeposit());
	printf("%25s%-10.3f\n", "Interest Rate: ", newAccount.GetInterestRate());
	printf("%25s%-10d\n", "Number of Years: ", newAccount.GetNumberOfYears());
	//switch to determine which item is selected, and thus gets highlighted
	newMenu.HideCursorBlink();
	newMenu.SetColor(240);
	switch (item) {
	case 1: {
		newMenu.SetNewCursor(17, 25);
		printf("%-10.2f\n", newAccount.GetInitialInvestment());
		break;
	}
	case 2: {
		newMenu.SetNewCursor(18, 25);
		printf("%-10.2f\n", newAccount.GetMonthlyDeposit());
		break;
	}
	case 3: {
		newMenu.SetNewCursor(19, 25);
		printf("%-10.3f\n", newAccount.GetInterestRate());
		break;
	}
	case 4: {
		newMenu.SetNewCursor(20, 25);
		printf("%-10d\n", newAccount.GetNumberOfYears());
		break;
	}
	default: {

	}
	}
	//reset the color
	newMenu.SetColor(15);
	
}


//this function draws everything... starts with the pages at the bottom of the table
void Draw::DrawEverything(Menu& newMenu, Account& newAccount, int page, int selection, Draw& newDraw, int item, int data) {
	system("cls");
	newMenu.SetColor(15);
	newMenu.SetNewCursor(14, 0);
	cout << setw(86) << setfill('-') << " " << endl;
	cout << setfill(' ');
	newMenu.SetNewCursor(15, 37);
	cout << "Page  " << page + 1 << " of " << newAccount.GetNumberOfPages() << endl;
	newMenu.SetNewCursor(15, 21);
	cout << "< <";
	newMenu.SetNewCursor(15, 62);
	cout << "> >";
	newMenu.SetNewCursor(0, 0);
	if (data == 0) {		//check to see if it's months or years to show
		newAccount.GetPages(page, newAccount, newDraw);
	}
	else if (data == 1) {
		newAccount.GetMonthPages(page, newAccount, newDraw);
	}
	
	newDraw.DrawMenu(newAccount, newMenu, item);	//draw the menu at the bottom
	DrawInstructions(newMenu);		//draw the instructions at the bottom

	//return to RunMainProgram
}

//draw the splash page and menu
 int Draw::DrawMainTitle(Menu& newMenu) {
	int selection = 1;
	string sub = "Banking for the masses.";
	string inst = "Use arrow keys and 'enter' to select.";
	
	string splash[6];
	splash[0] = "    ___    _      ______               __";
	splash[1] = "   /   |  (_)____/ ____/__  ____ _____/ /";
	splash[2] = "  / /| | / / ___/ / __/ _ \\/ __ `/ __  / ";
	splash[3] = " / ___ |/ / /  / /_/ /  __/ /_/ / /_/ /  ";
	splash[4] = "/_/  |_/_/_/   \\____/\\___/\\__,_/\\__,_/   ";
	splash[5] = "                                         ";
	
	
	int columns = newMenu.GetWindowWidth();
	int column = columns;
	int row = 2;
	column /= 2;
	column = column - (splash[0].length() / 2);
		
	for (int i = 0; i < 6; i++) {
		newMenu.SetNewCursor(row, column);
		cout << splash[i] << endl;
		row++;
	}
	row++;
	column = columns / 2 - (sub.length() / 2);
	newMenu.SetNewCursor(row, column);
	cout << sub << endl;

	column = columns / 2 - (inst.length() / 2);
	newMenu.SetNewCursor(20, column);
	cout << inst << endl;

	

	return row;
}

 //draws the about section below the menu
 void Draw::DrawAbout(Menu& newMenu, Account& newAccount, Draw& newDraw) {
	 system("cls");
	 vector<string> about = { "AirGead Banking Corp.", "Copyright © 2021", "All rights reserved." };
	 newMenu.MenuModifier(about);
	 
	 
	 int row = 0;
	 int column = newMenu.GetWindowWidth();
	 column = column / 2 - (about.at(0).length() / 2);
	 row = DrawMainTitle(newMenu) + 16;
	 
	 for (int i = 0; i < about.size(); i++) {
		 newMenu.SetNewCursor(row, column);
		 cout << about.at(i) << endl;
		 row++;
	 }

 }

 //draw the instructions for the main account window
 void Draw::DrawInstructions(Menu& newMenu) {
	 newMenu.SetNewCursor(23, 0);
	 cout << "**HOT KEYS: up/down to navigate inputs, 'enter' to change" << endl;
	 cout << "            left/right arrows to navigate pages" << endl;
	 cout << "            'm' to change view, 'i' to return to account input, 'q' to quit" << endl;
 }



