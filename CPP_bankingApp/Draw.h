#pragma once

#include "Menu.h"
#include "Account.h"
#include "Calculate.h"
#include <iostream>
#include <vector>

using namespace std;

class Draw
{
public:
	void DrawTable(Menu& menu, Account& newAccount, Calculate& calculator);
};

