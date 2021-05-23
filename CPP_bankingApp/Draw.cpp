#include "Draw.h"



void Draw::DrawTable(Menu& menu, Account& newAccount, Calculate& calculator) {
	
	printf("%-10s%-10s%-16s%-10s\n", "Year", "Deposit", "Interest", "Balance");
	for (int i = 0; i < newAccount.GetNumberOfYears(); i++) {
		//printf("%.2f", newAccount.GetYearlyBalance(i));
		
		//printf("%-10 d% -10 0.2f% -10 0.2f% 5s% 1s% -10 0.2f\n", i + 1, newAccount.GetMonthlyDeposit(), newAccount.GetYearlyInterestEarned(i), "%", "$" ,newAccount.GetYearlyBalance(i));
		printf("%-10d", i + 1);
		printf("%-10.2f", newAccount.GetMonthlyDeposit());
		//cout << "$";
		printf("% 1s", "$");
		printf("%-15.2f", newAccount.GetYearlyInterestEarned(i));
		printf("% 1s", "$");
		printf("%-10.2f", newAccount.GetYearlyBalance(i));
		cout << endl;
	}
	
	
	//printf("%.2f", newAccount.yearlyBalance.at(i));
	
}


