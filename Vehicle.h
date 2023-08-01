#pragma once
#include <iostream>
using namespace std;
class Vehicle
{
private:
	char* CompanyName;
	char* color;
	int NumberOfWheels;
	int PowerCC;
	char* TypeOfVehicle;

	
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

	Vehicle(const Vehicle&);
	Vehicle(char* = nullptr, char* = nullptr, int = 0);

	Vehicle& operator=(Vehicle&);

	void SetCompanyName(char*);
	char* GetCompanyName();

	void SetColor(char*);
	char* GetColor();

	void SetNumberOfWheels(int);
	int GetNumberOfWheels();

	void SetPowerCC(int);
	int GetPowerCC();

	void SetTypeOfVehicle(char*);
	char* GetTypeOfVehicle();

	virtual void checkType() = 0;
	virtual void Display()const;

	~Vehicle();
};