#pragma once
#include <iostream>
#include "Vehicle.h"
#include "Truck.h"
#include "Car.h"
#include "Bike.h"
using namespace std;

class AliMotors
{
	Vehicle** arr;
	int size;


public:

	AliMotors();
	AliMotors(const AliMotors&);

	const Vehicle* operator[](int)const;
	Vehicle* operator[](int);

	AliMotors& operator=(const AliMotors&);

	const int GetSize()const;

	void AddVehicle();

	void SearchVehicle(char*);
	bool SaveData(const char*)const;

	~AliMotors();
};