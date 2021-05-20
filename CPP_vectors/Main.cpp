#include <iostream>
#include <vector>
#include <string>

#include "NewFunction.h"
#include "Obj.h"

using namespace std;

int main() {



	vector<int> current;
	vector<NewFunction> moreCurrent;
	vector<Obj> currentObj;


	NewFunction thisFunction;



	thisFunction.vectorFunction(current);
	thisFunction.vectorFunction(moreCurrent);
	thisFunction.vectorFunction(currentObj);



	cout << "Hello" << endl;
}