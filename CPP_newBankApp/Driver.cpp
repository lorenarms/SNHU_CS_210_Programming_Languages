/*
* This is the project 2 submission for CS 210
* 
* This app is a banking app that takes user input for a savings account, and displays the
* balance and interest earned by year or month in pages of five
* 
* this app uses my "menu" modular, as well as simple key input instead of a number menu
* 
* This may be the best app in this list thus far
*/

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>

#include "Account.h"
#include "Calculate.h"
#include "Draw.h"
#include "Menu.h"


//had some major issues with circular inclusion; couldn't figure out the issue and had to
//completely start from scratch to narrow the problem down
//in the end, i found that i needed to foward declare some classes within others

using namespace std;

int main() {

	Account newAccount;
	Menu newMenu;
	Calculate newCalculate;
	Draw newDraw;
	vector<string> mainMenu = { "New Account", "About", "Quit" };
	bool outerRun = true;
	bool mainRun = true;
	int selection = 0;
	
	newMenu.SetColor(15);						//set color to standard
	newMenu.SetWindowSize(800, 600);			//set window size
	newMenu.HideCursorBlink();				//hide the blink for now
	newDraw.DrawMainTitle(newMenu);			//draw the main title
	newMenu.MenuModifier(mainMenu);			//modify the main menu to fit
	newMenu.DrawMenu(mainMenu, selection);	//draw the main menu

	while (mainRun) {		//outer loop for main menu, allow user to navigate menu
		
		newMenu.RunMenu(mainMenu, selection);
		if (selection == 1) {		//stop this loop and continue to the next
			mainRun = false;
		}
		else if (selection == 2) {		//just show the about info

			newDraw.DrawAbout(newMenu, newAccount, newDraw);
		}
		else if (selection == 3) {			//quit the program
			system("cls");
			return 0;
		}

	}

	while (outerRun) {
		system("cls");
		int innerRun = 2;
		newCalculate.UserInput(newAccount, newMenu, newDraw);		//get user input for the account, return here
		while (innerRun != 1 && innerRun != 0) {

			innerRun = newCalculate.RunMainProgram(newMenu, newAccount, newDraw);
			if (innerRun == 0) {			//run the main program, starting at RunMainProgram
				outerRun = false;
			}
			else if (innerRun == 1) {		//quit the program 
				break;
			}
		}

	}
	system("cls");

}