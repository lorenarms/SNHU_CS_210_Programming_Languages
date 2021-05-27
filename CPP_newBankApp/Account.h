#pragma once



#include <iostream>
#include <vector>

using namespace std;

class Draw;

class Account;




class Account {
public:
	void SetInitialInvestment(double x);
	void SetMonthlyDeposit(double x);
	void SetInterestRate(double x);
	void SetNumberOfYears(int x);
	void SetYearlyBalance();
	int SetNumberOfPages();
	int SetNumberOfMonthPages();

	double GetInitialInvestment();
	double GetMonthlyDeposit();
	double GetInterestRate();
	int GetNumberOfYears();
	double GetYearlyBalance(int i);
	double GetMonthlyBalance(int i);
	double GetYearlyInterestEarned(int i);
	double GetMonthlyInterestEarned(int i);
	int GetNumberOfPages();
	void GetMonthPages(int page, Account& newAccount, Draw& newDraw);
	void GetPages(int page, Account& newAccount, Draw& newDraw);

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
	

};