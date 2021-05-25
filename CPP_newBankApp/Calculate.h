#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;

class Menu;
class Draw;
class Account;

class Calculate {
public:

	void UserInput(Account& newAccount, Menu& newMenu, Draw& newDraw);
	bool RunMainProgram(Menu& newMenu, Account& newAccount, Draw& newDraw);
	int ChangeMonthlyDeposit(Menu& newMenu, Account& newAccount, Draw& newDraw);
	int ChangeInterestRate(Menu& newMenu, Account& newAccount, Draw& newDraw);

private:

	
};