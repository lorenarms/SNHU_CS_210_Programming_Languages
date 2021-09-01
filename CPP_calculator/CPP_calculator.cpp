/*
 * Calculator.cpp
 *
 *  Date: May 11, 2021
 *  Author: Lawrence Artl III
 * 
 * This was a set of code provided for a small assignment in CS 210
 * There were errors in the code and i had to debug them and resubmit a working
 * version
 * 
 * fixes are commented below
 */

#include <iostream>

using namespace std;

void main()
{
	char statement[100];			//not sure if this is necessary here
	int op1, op2;
	char operation;
	char answer = 'y';				//use single quotes for char type instead of double; also needed a ';'
		while (answer == 'y')		//change to match declared , made both 'y' because that's easier to type
		{
			cout << "Enter expression" << endl;
				cin >> op1 >> operation >> op2;									//op1 and op2 were reversed, makes subtraction inaccurate
			if (operation == '+')											//needed single quotes here, no ';' necessary
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;		//wrong-facing arrows
			if (operation == '-')											//no ';' necessary
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;		//wrong-facing arrows
			if (operation == '*')
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;	//incorrect sign displayed, no ';' at the end of the line
			if (operation == '/')
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
		}
}