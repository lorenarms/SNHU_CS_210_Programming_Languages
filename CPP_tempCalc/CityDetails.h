#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//store all cities in this class

class CityDetails
{
private:
	//constructor
	string cityName = "NoName";
	int cityTemp = -1;

public:
	//getter and setters
	void setCityName(string city) {
		cityName = city;
	}
	void setCityTemp(int temp) {
		cityTemp = temp;
	}
	string getCityName() const { return cityName; }
	int getCityTemp() const { return cityTemp; }
};

