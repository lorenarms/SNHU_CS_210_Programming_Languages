#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Account;

class Pages {
private:
	double yearPages[5][3];
	double monthPages[5][3];

public:
	void SetPages(double row[], int i) {
		for (int j = 0; j < 3; j++) {
			yearPages[i][j] = row[j];
		}

		
	}
	void GetPages(Pages page, int count = 5) {
		for (int i = 0; i < count; i++) {
			cout << "Year: " << yearPages[i][0];
			cout << "Interest Earned: " << yearPages[i][1];
			cout << "Balance: " << yearPages[i][2];
			cout << "    " << i;
			cout << endl;
		}
	}

};

class Account {
public:
	void SetInitialInvestment(double x);
	void SetMonthlyDeposit(double x);
	void SetInterestRate(double x);
	void SetNumberOfYears(int x);
	void SetYearlyBalance();
	int SetNumberOfPages();
	void SetPages();

	double GetInitialInvestment();
	double GetMonthlyDeposit();
	double GetInterestRate();
	int GetNumberOfYears();
	double GetYearlyBalance(int i);
	double GetYearlyInterestEarned(int i);
	int GetNumberOfPages();
	void GetPages(int page);

	void DisplayAllValues();

private:
	double initialInvestment = 0.00;
	double monthlyDeposit = 0.00;
	double interestRate = 0.00;
	int numberOfYears = 0;
	int pages = 0;
	std::vector<double> yearlyBalance = { 0.00 };
	std::vector<double> yearlyInterestEarned = { 0.00 };
	std::vector<double> monthlyBalance = { 0.00 };
	std::vector<double> monthlyInterestEarned = { 0.00 };
	std::vector<Pages> yearPages;
	std::vector<Pages> monthPages;


};