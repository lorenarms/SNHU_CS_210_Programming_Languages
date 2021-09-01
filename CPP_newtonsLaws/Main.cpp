/*
unfinished, meant to calculate Newton's Laws based on various inputs
*/

#include <iostream>
#include "SecondLaw.h"

using namespace std;

int main() {
	cout << "Calculate Newton's Laws" << endl;
	cout << "Enter '999' for the missing variable to solve for." << endl;

	double friction;
	double mass;
	double acceleration;
	double forceNet;
	double weight;
	double weightParallel;
	double weightPerpendicular;
	double angle;
	double normalForce;
	char inMenu = 'y';

	SecondLaw newLaw;

	while (inMenu == 'y') {

		
		cout << "Enter mass: ";
		cin >> mass;
		cout << "Enter fnet: ";
		cin >> forceNet;
		cout << "Enter acceleration: ";
		cin >> acceleration;
		newLaw.calculateMissing(forceNet, acceleration, mass);


		cout << "Calculate another? ";
		cin >> inMenu;
		
	}


	
}