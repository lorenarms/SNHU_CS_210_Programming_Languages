#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "CityDetails.h"
#include "Driver.h"




void Driver::ReadInputFile(vector<CityDetails>& cityList) {
	cout << "Reading input file function" << endl;
	ifstream inFS;
	string cityName;
	int cityTemp;
	CityDetails currentCity;

	inFS.open("FahrenheitTemperature.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file." << endl;
	}
	while (!inFS.eof()) {
		inFS >> cityName;
		inFS >> cityTemp;

		if (!inFS.fail()) {
			currentCity.setCityName(cityName);
			currentCity.setCityTemp(cityTemp);
			cityList.push_back(currentCity);
		}
	}
}

void Driver::DisplayCities(vector<CityDetails>& cityList) {
	for (int i = 0; i < cityList.size(); ++i) {
		cout << "City: " << cityList.at(i).getCityName() << endl;
		cout << "Temperature: " << cityList.at(i).getCityTemp() << endl;
		cout << endl;
	}
}



