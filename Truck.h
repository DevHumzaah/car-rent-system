#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck :public Vehicle
{

	double ContainerSize;
	char* category;
	bool FourWheelDrive;
	static int NumberOfTrucks;

	int countLength(const char *n)
	{
		int i = 0;
		while (n[i] != '\0')
		{
			i++;
		}
		return i;
	}

	void countcopy(char*& ptr, char* arr)
	{
		ptr = new char[countLength(arr) + 1];
		for (int i = 0; i < countLength(arr); i++)
		{
			ptr[i] = arr[i];
		}
		ptr[countLength(arr)] = '\0';
	}

public:

	Truck(Truck&);
	Truck(double = 0, char* = nullptr, bool = false, char* = nullptr, char* = nullptr, int = 0);

	istream& input(istream&);
	ostream& output(ostream&);

	Truck& operator=(Truck&);

	void SetContainerSize(double);
	double GetContainerSize();

	void SetCategory(char*);
	char* GetCategory();

	void SetFourWheelDrive(bool);
	bool GetFourWheelDrive();

	int GetNumberOfTrucks();

	void checkType();
	void Display()const;

	~Truck();
};