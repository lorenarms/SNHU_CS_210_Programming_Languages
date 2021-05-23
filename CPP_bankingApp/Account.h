#pragma once

#include <vector>

using namespace std;

class Account
{

private:
	double initialInvestment = 0.00;
	double monthlyDeposit = 0.00;
	double interestRate = 0.00;
	int numberOfYears = 0;
	std::vector<double> yearlyBalance = { 0.00 };
	std::vector<double> yearlyInterestEarned = { 0.00 };

public:
	
	void SetInitialInvestment(double x);
	void SetMonthlyDeposit(double x);
	void SetInterestRate(double x);
	void SetNumberOfYears(int x);
	void SetYearlyBalance();

	double GetInitialInvestment();
	double GetMonthlyDeposit();
	double GetInterestRate();
	int GetNumberOfYears();
	double GetYearlyBalance(int i);
	double GetYearlyInterestEarned(int i);

	void DisplayAllValues();
};

