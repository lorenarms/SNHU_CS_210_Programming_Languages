#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "City.h"
#include "ReadFile.h"


using namespace std;

int main()
{
	//vector<City> cityList;
	//City cityList;
	ReadFile fileInput;
	string cityList;
	fileInput.ReadNewFile(cityList);

	cout << "Success!" << endl;

	


}

