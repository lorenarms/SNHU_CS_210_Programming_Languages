#pragma once
#include <vector>

#include "Account.h"
#include "Menu.h"

using std::vector;

class Calculate
{
public:
	void UserInput(Account& newAccount);
	bool RunMainProgram(Menu& menu, Account& newAccount);

};

