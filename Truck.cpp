#include "Truck.h"

Truck::Truck(Truck& ob) :Vehicle(ob)
{
	this->NumberOfTrucks = ob.NumberOfTrucks;
	this->ContainerSize = ob.ContainerSize;
	this->FourWheelDrive = ob.FourWheelDrive;
	this->category = ob.category;
}
Truck::Truck(double s, char* cat, bool d, char* n, char* c, int p) :Vehicle(n, c, p)
{
	this->NumberOfTrucks++;
	this->ContainerSize = s;
	this->FourWheelDrive = d;
	this->category = cat;
}


istream& Truck::input(istream& CIN)
{
	char* name = new char[20];
	cout << "\tENTER COMPANY NAME : ";
	CIN >> name;

	SetCompanyName(name);

	char* color = new char[20];
	cout << "\n\tENTER COLOR : ";
	CIN >> color;
	cout << endl;
	SetColor(color);

	int wheels = 0;
	while (true)
	{
		cout << "\tENTER WHEELS : ";
		CIN >> wheels;
		cout << endl;
		if (wheels == 6 || wheels == 4)
		{
			SetNumberOfWheels(wheels);
			break;
		}
		else
		{
			cout << "TRUCK HAS 4 OR 6 WHEELS ...\n\n";
		}
	}

	int power = 0;
	while (true)
	{
		cout << "\tENTER POWER : ";
		CIN >> power;
		cout << endl;
		if (power <= 4500)
		{
			SetPowerCC(power);
			break;
		}
		else
		{
			cout << "POWER IS LESS THAN 4500 ...\n\n";
		}
	}

	while (true)
	{
		cout << "\tENTER CONTAINER SIZE : ";
		CIN >> this->ContainerSize;
		cout << endl;
		if (this->ContainerSize <= 90)
		{
			SetContainerSize(this->ContainerSize);
			break;
		}
		else
		{
			cout << "CONTAINER SIZE IS LESS THEN 90 ...\n\n";
		}
	}

	cout << "\tENTER CATEGORY OF CONTAINER (Double-cabin/Single-cabin) : ";
	CIN >> this->category;
	
	cout << "\n... IS IT 4X4 WHEEL DRIVE ? ...\n";
	cout << "\t1=(True)\tand\t0=(False) : ";
	CIN >> this->FourWheelDrive;
	cout << endl;

	if (this->FourWheelDrive == true)
	{
		SetNumberOfWheels(4);
	}
	
	return CIN;

}
ostream& Truck::output(ostream& COUT)
{
	COUT << "\n\tCOMPANY NAME : " << GetCompanyName();
	COUT << "\n\tCOLOR : " << GetColor();
	COUT << "\n\tNUMBER OF WHEELS : " << GetNumberOfWheels();
	COUT << "\n\tPOWER : " << GetPowerCC();
	COUT << "\n\tCONTAINER SIZE : " << this->ContainerSize;
	COUT << "\n\tCATEGORY : " << this->category;

	if (this->FourWheelDrive == true)
	{
		COUT << "\nIT IS 4X4 DRIVE ...\n";
	}
	COUT << "\n\tNUMBER OF TRUCKS : " << this->NumberOfTrucks << endl << endl;

	return COUT;

}


Truck& Truck::operator=(Truck& ob)
{
	if (this != &ob)
	{
		this->NumberOfTrucks = ob.NumberOfTrucks;
		this->ContainerSize = ob.ContainerSize;
		this->FourWheelDrive = ob.FourWheelDrive;
		this->category = ob.category;
	}

	return *this;

}


void Truck::SetContainerSize(double s)
{
	this->ContainerSize = s;
}
double Truck::GetContainerSize()
{

	return this->ContainerSize;

}

void Truck::SetCategory(char* category)
{
	int s = countLength(category);
	this->category = new char[s + 1];
	for (int i = 0; i <= s; i++)
	{
		this->category[i] = category[i];
	}
}
char* Truck::GetCategory()
{
	return category;

}

void Truck::SetFourWheelDrive(bool f)
{
	this->FourWheelDrive = f;
}
bool Truck::GetFourWheelDrive()
{
	if (this->FourWheelDrive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Truck::GetNumberOfTrucks()
{

	return this->NumberOfTrucks;

}
void Truck::checkType()
{
	if (this->FourWheelDrive == true && GetNumberOfWheels() == 4)
	{
		char* type = new char[6];
		SetTypeOfVehicle(type);
	}
	else if (GetNumberOfWheels() == 6)
	{
		char* type = new char[6];
		SetTypeOfVehicle(type);
	}
	else
	{
		char* notype = new char[13];
		SetTypeOfVehicle(notype);
	}
}
void Truck::Display()const
{
	Vehicle::Display();
	cout << "\t\tCONTAINER SIZE :	" << ContainerSize;
	cout << "\n\t\tCATEGORY :	" <<category;
	if (FourWheelDrive)
	{
		cout << "\n\t\t4X4 DRIVE : YES";
		cout << "\n--------------------------------------------------------------------------------------------------------\n";
	}
	else
	{
		cout << "\n\t\t4X4 DRIVE : NO";
		cout << "\n--------------------------------------------------------------------------------------------------------\n";
	}
}


Truck::~Truck()
{
	
	delete[] category;
	FourWheelDrive = false;
	
}