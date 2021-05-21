#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "CityDetails.h"
#include "Driver.h"

using namespace std;

int main() {
	
	vector<CityDetails> cityList;			//store all cities in a vector, pass by address

	Driver newDriver;						//create driver object to manipulate data

	newDriver.ReadInputFile(cityList);		//read the file

	//check if file was opened, if not, skip calculations
	if (cityList.size() != 0) {
		//newDriver.DisplayCities(cityList);	//display the cities
		newDriver.ConvertToCelsius(cityList);	//convert temperatures
		newDriver.WriteOutputFile(cityList);	//write the new file
	}
	cout << "Exiting program." << endl;
	

}