#include <iostream>
#include <vector>

using namespace std;

class Menu;

class Draw
{
public:
	void DrawTable(Menu& menu, Account& newAccount, int page);
	void DrawPages(Account& newAccount, int minEntry, int maxEntry);
	void DrawMenu(Account& newAccount, Menu& newMenu, int item);
	void DrawEverything(Menu& newMenu, Account& newAccount, int page, int selection, Draw& newDraw, int item);
	int DrawMainTitle(Menu& newMenu);
	void DrawAbout(Menu& newMenu, Account& newAccount, Draw& newDraw);
};