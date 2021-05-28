#include "Account.h"
#include "Draw.h"


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <cmath>

using namespace std;

//most porgram logic happens here
//the line between this class and the Calculate class is slightly blurred
//they could essentially be one class

//most getters are pretty simple
//some had to be more complicated to access the variables within Account

void Account::SetInitialInvestment(double x) {
	initialInvestment = x;
}
void Account::SetInterestRate(double x) {
	interestRate = x / 100;
}
void Account::SetMonthlyDeposit(double x) {
	monthlyDeposit = x;
}
void Account::SetNumberOfYears(int x) {
	numberOfYears = x;
	
}

//sets the yearly and monthly balances in the vectors, to be accessed later 
void Account::SetYearlyBalance() {
	yearlyBalance.clear();
	yearlyInterestEarned.clear();
	monthlyBalance.clear();
	monthlyInterestEarned.clear();
	double temp = 0;
	double monthlyInterest = 0.00;
	double yearly = initialInvestment;

	//need to calculate the number of years, then store the amount of interest and
	//ending balance in their own vectors
	for (int i = 0; i < numberOfYears; i++) {
		monthlyInterest = 0;
		for (int j = 0; j < 12; j++) {
			temp = (yearly + monthlyDeposit);
			temp = temp * (interestRate / 12);
			monthlyInterestEarned.emplace_back(temp);
			yearly += monthlyDeposit;
			yearly += temp;
			monthlyBalance.emplace_back(yearly);
			monthlyInterest += temp;
		}
		yearlyInterestEarned.emplace_back(monthlyInterest);
		yearlyBalance.emplace_back(yearly);

	}
	cout << endl;

}
int Account::YearsToPages(int x) {
	x = numberOfYears / 5;
	if (numberOfYears % 5 > 0) {	//is the number of years less than five or not evenly divisible by five?
									//ie the last page has less than five
						
		x = x + 1;			//then add 1 to the total (is already 0 if years is less than 5)
	}
	return x;
}


void Account::SetNumberOfPages(int x) {
	//set the number of pages to the param passed
	pages = x;
	
}

int Account::SetNumberOfMonthPages() {
	int x;
	x = numberOfYears * 12;
	//this one was tricky, for month amounts divisible by five, it kept adding an extra page
	//it did this bc i had the 'x = x / 5' outside the if statment below, so an amount that was
	//divisible by five also resulted in a remainder, which added 1 below
	//ex 5 years x 12 = 60, 60 / 5 = 12, 12 % 5 = 2, so 12 pages turned to 13, but 
	//there weren't enough entries for 13 pages, so once the user navigated to the 13th page
	//the program would crash
	if (x % 5 > 0) {
		x = x / 5;
		x = x + 1;
	}
	else {
		x = x / 5;
	}

	return x;
}

//this function had a similar issue to the one above, but the bug only arose
//once the user switch from months back to years, it would add extra pages that caused a crash
//similar solution, except i added an extra 'if else' to account for int division
//ex 4 / 5 = 0, so +1 makes x = 1

int Account::SetNumberOfYearPages() {
	int x;
	x = numberOfYears;
	x = x / 5;
	if (numberOfYears % 5 > 0) {
		x = x + 1;
	}
	else if (x == 0) {
		x = 1;
	}
	return x;
}


//this function handles the logic of constructing the pages to display 
//i kept this here so that the variables were more easily accessible by the function
//it was easier than passing references and variables to getters outside a class
//this could be moved at a later date
void Account::GetPages(int page, Account& newAccount, Draw& newDraw) {
	page += 1;
	int maxEntry = 0;
	int minEntry = 0;
	int count = yearlyBalance.size();
	
	if (yearlyBalance.size() % 5 == 0) {
		maxEntry = page * 5;
		minEntry = maxEntry - 5;
	}
	else if (yearlyBalance.size() % 5 > 0) {
		if (page == pages) {
			count = yearlyBalance.size() % 5;
			maxEntry = yearlyBalance.size();
			minEntry = maxEntry - count;
		}
		else {
			maxEntry = page * 5;
			minEntry = maxEntry - 5;
		}
	}
	//this function when called will ultimately call the DrawPages function
	newDraw.DrawPages(newAccount, minEntry, maxEntry);
}

//this function is the same as the one above, but passes variables for month pages instead of year
//pages
//again, 1: could be placed elsewhere, and 2: could be comnbined with the above for less redundant code
void Account::GetMonthPages(int page, Account& newAccount, Draw& newDraw) {
	page += 1;
	int maxEntry = 0;
	int minEntry = 0;
	int count = monthlyBalance.size();

	if (monthlyBalance.size() % 5 == 0) {
		maxEntry = page * 5;
		minEntry = maxEntry - 5;
	}
	else if (monthlyBalance.size() % 5 > 0) {
		if (page == pages) {
			count = monthlyBalance.size() % 5;
			maxEntry = monthlyBalance.size();
			minEntry = maxEntry - count;
		}
		else {
			maxEntry = page * 5;
			minEntry = maxEntry - 5;
		}
	}
	newDraw.DrawMonthPages(newAccount, minEntry, maxEntry);

}

//generic getters
double Account::GetInitialInvestment() {
	return initialInvestment;
}
double Account::GetInterestRate() {
	return interestRate;
}
double Account::GetMonthlyDeposit() {
	return monthlyDeposit;
}
int Account::GetNumberOfYears() {
	return numberOfYears;
}
double Account::GetYearlyBalance(int i) {
	return yearlyBalance.at(i);
}

double Account::GetMonthlyBalance(int i) {
	return monthlyBalance.at(i);
}

double Account::GetYearlyInterestEarned(int i) {
	return yearlyInterestEarned.at(i);
}

double Account::GetMonthlyInterestEarned(int i) {
	return monthlyInterestEarned.at(i);
}

int Account::GetNumberOfPages() {
	return pages;
}

//for debugging only
void Account::DisplayAllValues() {
	cout << initialInvestment << endl;
	cout << interestRate << endl;
	cout << monthlyDeposit << endl;
	cout << numberOfYears << endl;
}

