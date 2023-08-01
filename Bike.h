#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Bike :public Vehicle
{
	double height;
	bool SelfStart, DiscBrake;
	static int NumberOfBikes;

public:

	Bike(Bike&);
	Bike(double = 0, bool = false, bool = false, char* = nullptr, char* = nullptr, int = 0);

	istream& input(istream&);
	ostream& output(ostream&);

	Bike& operator=(Bike&);

	void SetHeight(double);
	double GetHeight();

	void SetSelfStart(bool);
	bool GetSelfStart();

	void SetDiscBreak(bool);
	bool GetDiscBrake();

	int GetNumberOfBikes();

	void checkType();
	void Display()const;

	~Bike();
};