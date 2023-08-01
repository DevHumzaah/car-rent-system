#include "Vehicle.h"
#include "Truck.h"
#include "Car.h"
#include "Bike.h"
#include "AliMotors.h"

int Truck::NumberOfTrucks;
int Car::NumberOfCars;
int Bike::NumberOfBikes;
ostream& operator<<(ostream& COUT, Truck& ob);
ostream& operator<<(ostream& COUT, Car& ob);
ostream& operator<<(ostream& COUT, Bike& ob);
void ShowVehicles(const AliMotors& ob);
void Menu();

int main()
{
	char c;
	AliMotors ob;
	while (true)
	{
		Menu();
		cout << "\tENTER SELECTED OPTION : ";
		cin >> c;

		if (c == 's' || c == 'S')
		{
			ShowVehicles(ob);
		}
		if (c == 'e' || c == 'E')
		{
			char* filename = new char[20];
			cout << "\n\tFILE NAME : ";
			cin >> filename;
			cout << endl;
			if (ob.SaveData(filename))
			{
				cout << "\n\tSUCCESSFULLY FILE CREATED !\n";
			}
			else
			{
				cout << "\n\tFILE NOT CREATED !\n";
			}
		}
		if (c == 'a' || c == 'A')
		{
			ob.AddVehicle();
		}
		if (c == 'f' || c == 'F')
		{
			char* type = new char[20];
			cout << "\n\tVEHICLE TYPE : ";
			cin >> type;
			cout << endl;
			ob.SearchVehicle(type);
		}
		if (c == 'Q' || c == 'q')
		{
			break;
		}
	}

	system("pause");
	return 0;
}

ostream& operator<<(ostream& COUT, Truck& ob)
{
	return ob.output(COUT);
}

ostream& operator<<(ostream& COUT, Car& ob)
{
	return ob.output(COUT);
}

ostream& operator<<(ostream& COUT, Bike& ob)
{
	return ob.output(COUT);
}

void ShowVehicles(const AliMotors& ob)
{
	cout << "\n\tTOTAL VEHICLES : " << ob.GetSize() << endl;
	for (int i = 0; i < ob.GetSize(); i++)
	{
		ob[i]->Display();
	}
}

void Menu()
{
	cout << endl;
	cout << "<-------------------------Ali MOTORS----------------------->\n\n\n";
	cout << "\tS\tSHOW VEHICLES LIST \n";
	cout << "\tE\tCREATE DATA OUTPUT FILE (OUTPUT FILE) \n";
	cout << "\tA\tADD NEW VEHICLE\n";
	cout << "\tF\tFIND VEHICLE BY TYPE\n";
	cout << "\tQ\tQUIT PROGRAM\n\n";
}