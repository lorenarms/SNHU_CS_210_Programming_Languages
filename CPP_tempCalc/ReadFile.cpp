#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "City.h"
#include "ReadFile.h"

using namespace std;

void ReadFile::ReadNewFile(string cityList) {
	ifstream inFS;
	
	cout << "Attempting to open file FahrenheitTemperature.txt" << endl;
	inFS.open("FahrenheitTemperature.txt");

	if (!inFS.is_open()) {
		cout << "Could not open the file!" << endl;
		return 1;
	}

	cout << "Reading file" << endl;
	cout << "Closing the file" << endl;
	inFS.close();


}

