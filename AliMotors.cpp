#include "AliMotors.h"
#include <iostream>
#include <fstream>
using namespace std;

AliMotors::AliMotors()
{
	this->size = 0;
	this->arr = new Vehicle *[20];
}
AliMotors::AliMotors(const AliMotors& ob)
{
	this->size = ob.size;
	this->arr = ob.arr;
}


const Vehicle* AliMotors::operator[](int index)const
{
	if (index >= 0 && index < 20)
	{
		return this->arr[index];
	}
	else
	{
		return this->arr[0];
	}
}
Vehicle* AliMotors::operator[](int index)
{
	if (index >= 0 && index < 20)
	{
		return this->arr[index];
	}
	else
	{
		return this->arr[0];
	}
}


AliMotors& AliMotors::operator=(const AliMotors& ob)
{
	if (this != &ob)
	{
		this->arr = ob.arr;
		this->size = ob.size;
	}

	return *this;

}


void AliMotors::AddVehicle()
{
	Vehicle* temp = NULL;
	char choice;
	while (true)
	{
		cout << "\n\tPRESS T FOR TRUCK";
		cout << "\n\tPRESS C FOR CAR";
		cout << "\n\tPRESS B FOR BIKE";
		cout << "\n\tPRESS 0 FOR MAIN MENU";
		cout << "\n\n\tENTER CHOICE : ";

		cin >> choice;

		if (choice == 'b' || choice == 'B')
		{
			char* name = new char[6];
			char* color = new char[6];

			Bike* obj = new Bike(10, true, true, name, color, 2);
			obj->input(cin);
			obj->checkType();

			this->arr[this->size++] = obj;
			cout << "\nVEHICLE ADDED SUCCESSFULLY...\n";
		}
		else if (choice == 'C' || choice == 'c')
		{
			char* name = new char[6];
			Car* obj = new Car(4, name, 4, name, name, 2);
			obj->input(cin);
			obj->checkType();

			this->arr[this->size++] = obj;
			cout << "\nVEHICLE ADDED SUCCESSFULLY...\n";
		}
		else if (choice == 't' || choice == 'T')
		{
			char* name = new char[6];
			Truck* obj = new Truck(4, name, 4, name, name, 2);
			obj->input(cin);
			obj->checkType();

			this->arr[this->size++] = obj;
			cout << "\nVEHICLE ADDED SUCCESSFULLY...\n";
		}
		else if (choice == '0')
		{
			break;
		}
		else
		{
			cout << "\nENTER CORRECT CHOICE...\n";
		}
	}
}



void AliMotors::SearchVehicle(char* se)
{
	int flag = 0, index = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i]->GetTypeOfVehicle(), se))
		{
			index = i;
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tVEHICLE'S ARE : \n";
		for (int i = index; i < size; i++)
		{
			cout << "\n\t\tVEHICLE # :		    " << i + 1;
			cout << "\n\t\tCOMPANY :	        " << arr[i]->GetCompanyName();
			cout << "\n\t\tCOLOR :	            " << arr[i]->GetColor();
			cout << "\n\t\tTYPE OF VEHICLE :	" << arr[i]->GetTypeOfVehicle();
			cout << "\n\t\tNUMBER OF WHEELS :	" << arr[i]->GetNumberOfWheels();
			cout << "\n\t\tPOWER CC :	        " << arr[i]->GetPowerCC();
		}
	}
	else
	{
		cout << "\n\tNO ACCOUNT FOUND !\n";
	}
}


bool AliMotors::SaveData(const char* fname)const
{
	ofstream FOUT;
	char* name = new char[6];
	char* color = new char[6];
	FOUT.open(fname);
	if (FOUT.is_open())
	{
		FOUT << "\n\tVehicle Information\n";
		FOUT << "\n\t------------------------\n";
		FOUT << "\n\tNUMBER OF BIKES  : " << &Bike::GetNumberOfBikes;
		FOUT << "\n\tNUMBER OF CARS   : " << &Car::GetNumberOfCars;
		FOUT << "\n\tNUMBER OF TRUCKS : " << &Truck::GetNumberOfTrucks;
		FOUT << "\n\nCompany Name:		Type:		Color:		Power:";
		FOUT << "\n-----------------------------------------------------------------------------------\n";

		for (int i = 0; i < size; i++)
		{
			FOUT << arr[i]->GetCompanyName() << "			" << arr[i]->GetTypeOfVehicle() << "		" << arr[i]->GetColor() << "		" << arr[i]->GetPowerCC() << endl;
		}
		return true;
	}
	else
	{
		return false;
	}
	FOUT.close();
}

const int AliMotors::GetSize()const
{
	return this->size;
}


AliMotors::~AliMotors()
{
	/*delete[] arr;
	arr = nullptr;
	size = 0;*/
}