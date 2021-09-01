/*
This is the start of a personal project, meant to be a simple card game with
console graphics
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "Card.h"
#include "Menu.h"
#include "Game.h"



int Game::RunGame() {

	newMenu.SetWindowSize(800, 400);
	newMenu.HideCursorBlink();
	MainMenu(newMenu);

	return 0;

}

int Game::MainMenu(Menu& newMenu) {
	int selection = 0;
	vector <string> menu = { "New Game", "Continue", "Instructions", "About", "Quit" };

	newMenu.MenuModifier(menu);
	newMenu.RunMenu(menu, selection);
	return selection;

}