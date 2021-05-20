#include <vector>
#include <string>
#include <iostream>
#include <fstream>



using namespace std;

class City {
private:
	string cityName = "NoName";
	int temperature = -999;
public:
	void setCityName(string city) {
		cityName = city;
	}
	void setCityTemp(int temp) {
		temperature = temp;
	}
	string getCityName() const { return cityName; }
	int getCityTemp() const { return temperature; }

};

void ReadCityList(vector<City>& cityList) {
	ifstream inFS;
	string cityName;
	int cityTemp;
	City currentCity;

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

void DisplayCities(const vector<City>& cityList) {
	for (int i = 0; i < cityList.size(); ++i) {
		cout << "City: " << cityList.at(i).getCityName() << endl;
		cout << "Temperature: " << cityList.at(i).getCityTemp() << endl;
		cout << endl;
	}
}

int main() {
	vector<City> cityList;

	ReadCityList(cityList);
	DisplayCities(cityList);
	


}