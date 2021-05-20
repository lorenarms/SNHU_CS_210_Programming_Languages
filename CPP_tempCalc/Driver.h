#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "CityDetails.h"


using namespace std;


class Driver
{
public:
	void ReadInputFile(vector<CityDetails>& cityList);
	void DisplayCities(vector<CityDetails>& cityList);

};

