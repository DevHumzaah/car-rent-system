#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;


class Car :public Vehicle
{
private:
	int NumberOfDoors;
	char* transmission;
	int NumberOfSeats;
	static int NumberOfCars;

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

	Car(Car&);
	Car(int = 0, char* = nullptr, int = 0, char* = nullptr, char* = nullptr, int = 0);

	istream& input(istream&);
	ostream& output(ostream&);

	Car& operator=(Car&);

	void SetNumberOfDoors(int);
	int GetNumberOfDoors();

	void SetTransmission(char*);
	char* GetTransmission();

	void SetNumberOfSeats(int);
	int GetNumberOfSeats();

	int GetNumberOfCars();

	void checkType();
	void Display()const;

	~Car();
};