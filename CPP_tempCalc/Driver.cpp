#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "CityDetails.h"
#include "Driver.h"




void Driver::ReadInputFile(vector<CityDetails>& cityList) {
	
	//input driver for reading file
	cout << "Reading FahrenheitTemperature.txt." << endl;
	ifstream inFS;
	string cityName;
	int cityTemp;
	CityDetails currentCity;		//temporary variable

	inFS.open("FahrenheitTemperature.txt");

	//try to open the file, otherwise return to main
	if (!inFS.is_open()) {
		cout << "Could not open file." << endl;
		return;
	}
	//while file is open but not done reading, loop through one at a time and file each entry into an index
	//of the vector
	while (!inFS.eof()) {
		inFS >> cityName;
		inFS >> cityTemp;

		if (!inFS.fail()) {
			currentCity.setCityName(cityName);
			currentCity.setCityTemp(cityTemp);
			cityList.push_back(currentCity);
		}
	}
	cout << "Success! File opened." << endl;
}

void Driver::WriteOutputFile(vector<CityDetails>& cityList) {
	
	//write to the output file, display message
	cout << "Writing to output file." << endl;
	ofstream outFS;
	string cityName;
	int cityTemp;
	CityDetails currentCity;

	outFS.open("CelsiusTemperature.txt");

	//attempt to open file
	if (!outFS.is_open()) {
		cout << "Could not open output file, file may not exist." << endl;
		return;
	}
	for (int i = 0; i < cityList.size(); i++) {
		//loop and write to new file in same format as original file
		outFS << cityList.at(i).getCityName() << " " << cityList.at(i).getCityTemp() << endl;

	}
	//close the file
	outFS.close();
}

void Driver::ConvertToCelsius(vector<CityDetails>& cityList) {
	//converting to celsius
	int cityTemp;
	int celsiusTemp;
	cout << "Converting to Celsius..." << endl;
	for (int i = 0; i < cityList.size(); i++) {
		//break up calculations so it doesn't freak out
		cityTemp = cityList.at(i).getCityTemp();
		cityTemp -= 32;
		cityTemp *= 5;
		cityTemp /= 9;
		//write new value to vector
		cityList.at(i).setCityTemp(cityTemp);
		
	}
	cout << "Successfully converted all temperatures to Celsius. " << endl;

}

void Driver::DisplayCities(vector<CityDetails>& cityList) {
	//for displaying contents of the file
	for (int i = 0; i < cityList.size(); ++i) {
		cout << "City: " << cityList.at(i).getCityName() << endl;
		cout << "Temperature: " << cityList.at(i).getCityTemp() << endl;
		cout << endl;
	}
}



