#include "Calculate.h"
#include "Account.h"
#include "Menu.h"
#include "Draw.h"



void Draw::DrawTable(Menu& menu, Account& newAccount, int page) {

	printf("%-10s%-10s%-16s%-10s\n", "Year", "Deposit", "Interest", "Balance");
	for (int i = 0; i < newAccount.GetNumberOfYears(); i++) {
		printf("%-10d", i + 1);
		printf("%-10.2f", newAccount.GetMonthlyDeposit());
		printf("% 1s", "$");
		printf("%-15.2f", newAccount.GetYearlyInterestEarned(i));
		printf("% 1s", "$");
		printf("%-10.2f", newAccount.GetYearlyBalance(i));
		cout << endl;
	}
}




