#pragma once
class SecondLaw
{
public:
	double calculateAcceleration(double m, double fnet);
	double calculatefNet(double m, double a);
	double calculateMass(double fnet, double a);
	void calculateMissing(double fnet, double a, double m);
};

