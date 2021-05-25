#include "Account.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <cmath>

using namespace std;

class Pages;

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
		cout << numberOfYears % 5 << endl;
		x = x + 1;
	}
	
	return x;
}

void Account::SetPages() {
	double row[] = { 0.00, 0.00, 0.00 };
	Pages newPage;
	yearPages.clear();
	for (int i = 0; i < numberOfYears; i++) {
		row[0] = i + 1.00;
		row[1] = yearlyInterestEarned.at(i);
		row[2] = yearlyBalance.at(i);

		

		newPage.SetPages(row, i);
	}
	yearPages.emplace_back(newPage);

}

void Account::GetPages(int page) {
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
	
	printf("%10s%5s%-10s%-16s%-10s\n", "Year", "     ", "Deposit", "Interest", "Balance");
	//cout << "Min: " << minEntry << "   Max: " << maxEntry << endl;
	for (int i = minEntry; i < maxEntry; i++) {
		printf("%10d", i + 1);
		printf("%5s", "     ");
		printf("%-10.2f", GetMonthlyDeposit());
		printf("% 1s", "$");
		printf("%-15.2f", GetYearlyInterestEarned(i));
		printf("% 1s", "$");
		printf("%-10.2f", GetYearlyBalance(i));
		cout << endl;
		cout << endl;
		
		
	}
	
	
	

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

double Account::GetYearlyInterestEarned(int i) {
	return yearlyInterestEarned.at(i);
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

