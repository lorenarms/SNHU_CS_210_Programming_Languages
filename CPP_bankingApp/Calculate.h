#pragma once
#include <vector>


using std::vector;

class Menu;
class Account;
class Draw;

class Calculate
{
public:

	void UserInput(Account& newAccount);
	bool RunMainProgram(Menu& menu, Account& newAccount);
	int ChangeMonthlyDeposit(Menu& menu, Account& newAccount);
	int ChangeInterestRate(Menu& menu, Account& newAccount);


};

