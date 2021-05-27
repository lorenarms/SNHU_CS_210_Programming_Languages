#include "Account.h"
#include "Draw.h"


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <cmath>

using namespace std;


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
	pages = SetNumberOfPages();
}

void Account::SetYearlyBalance() {
	yearlyBalance.clear();
	yearlyInterestEarned.clear();
	monthlyBalance.clear();
	monthlyInterestEarned.clear();
	double temp = 0;
	double monthlyInterest = 0.00;
	double yearly = initialInvestment;


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

int Account::SetNumberOfPages() {
	int x;
	x = numberOfYears / 5;
	if (numberOfYears % 5 > 0) {
		//cout << numberOfYears % 5 << endl;
		x = x + 1;
	}
	
	return x;
}

int Account::SetNumberOfMonthPages() {
	int x;
	x = numberOfYears * 12;
	x = x / 5;
	if (x % 5 > 0) {
		//cout << numberOfYears % 5 << endl;
		x = x + 1;
	}

	return x;
}



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
	newDraw.DrawPages(newAccount, minEntry, maxEntry);
	
}

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

void Account::DisplayAllValues() {
	cout << initialInvestment << endl;
	cout << interestRate << endl;
	cout << monthlyDeposit << endl;
	cout << numberOfYears << endl;
}

