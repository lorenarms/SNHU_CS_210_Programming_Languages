#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "City.h"
#include "ReadFile.h"


void City::setCityName(string name) {
	cityName = name;
}
void City::setCityTemperature(int temp) {
	cityTemperature = temp;
}

string City::getCityName() const {
	return cityName;
}
int City::getCityTemperature() const {
	return cityTemperature;
}