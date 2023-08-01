#include "Car.h"

Car::Car(Car& ob) :Vehicle(ob)
{
	this->NumberOfDoors = ob.NumberOfDoors;
	this->NumberOfSeats = ob.NumberOfSeats;
	this->NumberOfCars = ob.NumberOfCars;
	this->transmission = ob.transmission;
}
Car::Car(int door, char* trans, int seat, char* n, char* c, int p) :Vehicle(n, c, p)
{
	this->NumberOfDoors = door;
	this->NumberOfSeats = seat;
	this->NumberOfCars++;
	this->transmission = trans;
}


istream& Car::input(istream& CIN)
{
	while (true)
	{
		char* name = new char[20];
		cout << "\tENTER COMPANY NAME : ";
		CIN >> name;

		SetCompanyName(name);

		char* color = new char[20];
		cout << "\n\tENTER COLOR : ";
		CIN >> color;

		SetColor(color);

		int wheels = 0;
		while (true)
		{
			cout << "\n\tENTER WHEELS : ";
			CIN >> wheels;

			if (wheels == 4)
			{
				SetNumberOfWheels(wheels);
				break;
			}
			else
			{
				cout << "\n\tCAR HAS ONLY 4 WHEELS...\n";
			}
		}

		int power = 0;
		while (true)
		{
			cout << "\n\tENTER POWER : ";
			CIN >> power;

			if (power <= 4500)
			{
				SetPowerCC(power);
				break;
			}
			else
			{
				cout << "\n\tPOWER IS LESS THEN 4500 ...\n";
			}
		}

		while (true)
		{
			cout << "\n\tENTER NUMBER OF DOORS : ";
			CIN >> this->NumberOfDoors;

			if (this->NumberOfDoors == 4 || this->NumberOfDoors == 2)
			{
				SetNumberOfDoors(this->NumberOfDoors);
				break;
			}
			else
			{
				cout << "\n\tCAR HAS 2 DOORS OR 4 DOORS...\n";
			}
		}

		cout << "\n\tENTER TRANSMISSION (Automatic/Manual) : ";
		CIN >> this->transmission;

		while (true)
		{
			cout << "\n\tENTER NUMBER OF SEATS : ";
			CIN >> this->NumberOfSeats;

			if (this->NumberOfSeats == 2 && this->NumberOfDoors == 2)
			{
				SetNumberOfSeats(this->NumberOfSeats);
				break;
			}
			else if (this->NumberOfDoors == 4 && this->NumberOfSeats == 4)
			{
				SetNumberOfSeats(this->NumberOfSeats);
				break;
			}
			else
			{
				cout << "\n\tNUMBER OF SEATS SHOULD BE 2 OR 4...\n";
			}
		}
		break;
	}

	return CIN;

}
ostream& Car::output(ostream& COUT)
{
	COUT << "\n\tCOMPANY NAME : " << GetCompanyName();
	COUT << "\n\tCOLOR : " << GetColor();
	COUT << "\n\tNUMBER OF WHEELS : " << GetNumberOfWheels();
	COUT << "\n\tPOWER : " << GetPowerCC();
	COUT << "\n\tNUMBER OF DOORS : " << this->NumberOfDoors;
	COUT << "\n\tTRANSMISSION : " << this->transmission;
	COUT << "\n\tNUMBER OF SEATS : " << this->NumberOfSeats;
	COUT << "\n\tNUMBER OF CARS : " << this->NumberOfCars;

	return COUT;

}


Car& Car::operator=(Car& ob)
{
	if (this != &ob)
	{
		this->NumberOfDoors = ob.NumberOfDoors;
		this->NumberOfSeats = ob.NumberOfSeats;
		this->NumberOfCars = ob.NumberOfCars;
		this->transmission = ob.transmission;
	}

	return *this;

}


void Car::SetNumberOfDoors(int d)
{
	NumberOfDoors = d;
}
int Car::GetNumberOfDoors()
{

	return this->NumberOfDoors;

}

void Car::SetTransmission(char* transmission)
{
	int s = countLength(transmission);
	this->transmission = new char[s + 1];
	for (int i = 0; i <= s; i++)
	{
		this->transmission[i] = transmission[i];
	}
}
char* Car::GetTransmission()
{
	return transmission;

}


void Car::SetNumberOfSeats(int s)
{
	this->NumberOfSeats = s;
}
int Car::GetNumberOfSeats()
{

	return this->NumberOfSeats;

}


int Car::GetNumberOfCars()
{

	return this->NumberOfCars;

}


void Car::checkType()
{
	if (GetNumberOfWheels() == 4)
	{
		char* type = new char[4];
		SetTypeOfVehicle(type);
	}
	else
	{
		char* notype = new char[13];
		SetTypeOfVehicle(notype);
	}
}
void Car::Display()const
{
	Vehicle::Display();
	cout << "\n\t\tNUMBER OF DOORS : " << NumberOfDoors;
	cout << "\n\t\tTRANSMISSION : " << transmission;
	cout << "\n\t\tNUMBER OF SEATS : " << NumberOfSeats;
	cout << "\n--------------------------------------------------------------------------------------------------------\n";
}


Car::~Car()
{

	delete[] transmission;

}