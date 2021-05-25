#include <iostream>
#include <vector>

using namespace std;

class Account;
class Menu;

class Draw
{
public:
	void DrawTable(Menu& menu, Account& newAccount, int page);
};