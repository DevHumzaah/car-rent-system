#include "Bike.h"

Bike::Bike(Bike& ob) :Vehicle(ob)
{
	this->height = ob.height;
	this->SelfStart = ob.SelfStart;
	this->DiscBrake = ob.DiscBrake;
	this->NumberOfBikes = ob.NumberOfBikes;
}
Bike::Bike(double hei, bool sel, bool dis, char* n, char* c, int p) :Vehicle(n, c, p)
{
	this->height = hei;
	this->SelfStart = sel;
	this->DiscBrake = dis;
	this->NumberOfBikes++;
}


istream& Bike::input(istream& CIN)
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

			if (wheels == 2)
			{
				SetNumberOfWheels(wheels);
				break;
			}
			else
			{
				cout << "\n\tBIKE HAS ONLY 2 WHEELS ...\n";
			}
		}
		int power = 0;
		while (true)
		{
			cout << "\n\tENTER POWER : ";
			CIN >> power;

			if (power <= 150)
			{
				SetPowerCC(power);
				break;
			}
			else
			{
				cout << "\n\tPOWER IS LESS THAN 150...\n";
			}
		}

		while (true)
		{
			cout << "\n\tENTER HEIGHT : ";
			CIN >> this->height;

			if (this->height <= 80)
			{
				SetHeight(this->height);
				break;
			}
			else
			{
				cout << "\n\tHEIGHT IS NOT GREATER THAN 80...\n";
			}
		}

		cout << "\n\t...IS IT SELF START OR NOT ?...\n";
		cout << "\t1=(TRUE) and 0=(FALSE) : ";
		CIN >> this->SelfStart;

		cout << "\n\t...IS IT DISC BRAKE OR NOT ?...\n";
		cout << "\t1=(TRUE) and 0=(FALSE) : ";
		CIN >> this->DiscBrake;
		cout << endl;
		break;
	}

	return CIN;

}
ostream& Bike::output(ostream& COUT)
{
	COUT << "\n\tCOMPANY NAME : " << GetCompanyName();
	COUT << "\n\tCOLOR : " << GetColor();
	COUT << "\n\tNUMBER OF WHEELS : " << GetNumberOfWheels();
	COUT << "\n\tPOWER : " << GetPowerCC();
	COUT << "\n\tHEIGHT : " << this->height;
	if (this->SelfStart)
	{
		COUT << "\n\tIT IS SELF START...";
	}
	if (this->DiscBrake)
	{
		COUT << "\n\tIT HAS DISC BRAKE...";
	}
	COUT << "\n\tNUMBER OF BIKES : " << this->NumberOfBikes;

	return COUT;

}


Bike& Bike::operator=(Bike& ob)
{
	if (this != &ob)
	{
		this->DiscBrake = ob.DiscBrake;
		this->height = ob.height;
		this->SelfStart = ob.SelfStart;
		this->NumberOfBikes = ob.NumberOfBikes;
	}

	return *this;

}


void Bike::SetHeight(double hei)
{
	this->height = hei;
}
double Bike::GetHeight()
{
	return this->height;
}


void Bike::SetSelfStart(bool sel)
{
	this->SelfStart = sel;
}
bool Bike::GetSelfStart()
{
	if (this->SelfStart)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Bike::SetDiscBreak(bool dis)
{
	this->DiscBrake = dis;
}
bool Bike::GetDiscBrake()
{
	if (this->DiscBrake)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Bike::GetNumberOfBikes()
{
	return this->NumberOfBikes;
}


void Bike::checkType()
{
	if (GetNumberOfWheels() == 2)
	{
		char* type = new char[5];
		SetTypeOfVehicle(type);
	}
	else {
		char* notype = new char[13];
		SetTypeOfVehicle(notype);
	}
}
void Bike::Display()const
{
	Vehicle::Display();
	cout << "\n\t\tHEIGHT :	" <<height;
	if (SelfStart)
	{
		cout << "\n\t\tSELF START :	YES";
	}
	else
	{
		cout << "\n\t\tSELF START :	NO";
	}
	if (DiscBrake)
	{
		cout << "\n\t\tDISC BRAKE :	YES";
	}
	else
	{
		cout << "\n\t\tDISC BRAKE :	NO";
	}
	cout << "\n--------------------------------------------------------------------------------------------------------\n";
}


Bike::~Bike()
{
	this->height = 0;
	this->SelfStart = false;
	this->DiscBrake = false;
	this->NumberOfBikes = 0;
}