#include "Account.h"

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
}

void Account::SetYearlyBalance() {
	yearlyBalance.clear();
	yearlyInterestEarned.clear();
	double temp = 0;
	double monthlyInterest = 0.00;
	double yearly = initialInvestment;

	
	for (int i = 0; i < numberOfYears; i++) {
		monthlyInterest = 0;
		for (int j = 0; j < 12; j++) {
			temp = (yearly + monthlyDeposit);
			temp = temp * (interestRate / 12);

			yearly += monthlyDeposit;
			yearly += temp;
			monthlyInterest += temp;
			
			
		}
		yearlyInterestEarned.emplace_back(monthlyInterest);
		yearlyBalance.emplace_back(yearly);

	}
	cout << endl;

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

void Account::DisplayAllValues() {
	cout << initialInvestment << endl;
	cout << interestRate << endl;
	cout << monthlyDeposit << endl;
	cout << numberOfYears << endl;
}
