#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "City.h"
#include "ReadFile.h"

using namespace std;

class City {
public:

	void setCityName(string name);
	void setCityTemperature(int temp);

	string getCityName() const;
	int getCityTemperature() const;

private:
	string cityName;
	int cityTemperature;

};