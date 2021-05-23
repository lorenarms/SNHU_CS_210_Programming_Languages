#pragma once


#include <iostream>
#include "Windows.h"
#include "Menu.h"
#include "Card.h"


class Game {
public:
	int MainMenu(Menu& newMenu);
	int RunGame();


	Menu newMenu;


};