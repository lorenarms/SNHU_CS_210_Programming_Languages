#include "SecondLaw.h"
#include <iostream>

using namespace std;

double SecondLaw::calculateAcceleration(double m, double fnet) {
	double accel = 0;
	accel = fnet / m;
	return accel;
}
double SecondLaw::calculatefNet(double m, double a) {
	double net = m * a;
	return net;
}
double SecondLaw::calculateMass(double fnet, double a) {
	double mass = fnet / a;
	return mass;
}
void SecondLaw::calculateMissing(double fnet, double a, double m) {
	if (fnet == 999) {
		fnet = a * m;
		cout << "Net force is " << fnet << endl;

	}
	else if (a == 999) {
		a = fnet / m;
		cout << "Acceleration is " << a << endl;
	}
	else if (m == 999) {
		m = fnet / a;
		cout << "Mass of the system is " << m << endl;
	}
}