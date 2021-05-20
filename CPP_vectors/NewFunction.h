#pragma once
#include <vector>
#include <string>
#include "Obj.h"

using namespace std;


class NewFunction {
public:
	void vectorFunction(std::vector<int>& current);
	void vectorFunction(std::vector<NewFunction>& current);
	void vectorFunction(std::vector<Obj>& current);

	//string userName = "NoName";
	int rating = -1;
	int coins = 0;
};
