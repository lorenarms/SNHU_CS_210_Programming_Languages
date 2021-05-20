#include <iostream>
#include <vector>
#include <string>

#include "NewFunction.h"
#include "Obj.h"

using namespace std;

void NewFunction::vectorFunction(vector<int>& current) {
	cout << "int vector function" << endl;
}
void NewFunction::vectorFunction(std::vector<NewFunction>& current) {
	cout << "class vector function" << endl;
}

void NewFunction::vectorFunction(std::vector<Obj>& current) {
	cout << "class obj vector function" << endl;

}

