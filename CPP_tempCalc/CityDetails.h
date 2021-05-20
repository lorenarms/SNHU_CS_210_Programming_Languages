#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>



using namespace std;


class CityDetails
{
private:
	string cityName = "NoName";
	int cityTemp = -1;

public:
	void setCityName(string city) {
		cityName = city;
	}
	void setCityTemp(int temp) {
		cityTemp = temp;
	}
	string getCityName() const { return cityName; }
	int getCityTemp() const { return cityTemp; }
};

