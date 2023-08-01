#include "Vehicle.h"

Vehicle::Vehicle(const Vehicle& ob)
{
	CompanyName= ob.CompanyName;
	color= ob.color;
	NumberOfWheels = ob.NumberOfWheels;
	PowerCC = ob.PowerCC;
	TypeOfVehicle= ob.TypeOfVehicle;
}
Vehicle::Vehicle(char* n, char* c, int p)
{
	this->PowerCC = p;
	this->CompanyName = n;
	this->color=c;
}


Vehicle& Vehicle::operator=(Vehicle& ob)
{
	if (this != &ob)
	{
		this->NumberOfWheels = ob.NumberOfWheels;
		this->TypeOfVehicle= ob.TypeOfVehicle;
		this->CompanyName = ob.CompanyName;
		this->color = ob.color;
		this->PowerCC = ob.PowerCC;
	}

	return *this;

}
int countLength(const char *n)
{
	int i = 0;
	while (n[i] != '\0')
	{
		i++;
	}
	return i;
}

void Vehicle::SetCompanyName(char  *CompanyName)
{
	
	int s = countLength(CompanyName);
	this->CompanyName = new char[s + 1];
	for (int i = 0; i <= s; i++)
	{
		this->CompanyName[i] =	CompanyName[i];
	}
}
char* Vehicle::GetCompanyName()
{
	return CompanyName;

}


void Vehicle::SetColor(char* color)
{
	int s = countLength(color);
	this->color= new char[s + 1];
	for (int i = 0; i <= s; i++)
	{
		this->color[i] = color[i];
	}
}

char* Vehicle::GetColor()
{
	return color;

}


void Vehicle::SetNumberOfWheels(int w)
{
	this->NumberOfWheels = w;
}
int Vehicle::GetNumberOfWheels()
{

	return this->NumberOfWheels;

}


void Vehicle::SetPowerCC(int p)
{
	this->PowerCC = p;
}
int Vehicle::GetPowerCC()
{

	return this->PowerCC;

}



void Vehicle::SetTypeOfVehicle(char* TypeOfVehicle)
{
	int s = countLength(TypeOfVehicle);
	this->TypeOfVehicle = new char[s + 1];
	for (int i = 0; i <= s; i++)
	{
		this->TypeOfVehicle[i] = TypeOfVehicle[i];
	}
}
	
char* Vehicle::GetTypeOfVehicle()
{
	return TypeOfVehicle;
}


void Vehicle::Display()const
{
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "\n\t\tCompany : " << CompanyName;
	cout << "\n\t\tColor :   " << color;
	cout << "\n\t\tPower :	 " << PowerCC;
	cout << "\n\t\tType :	 " << TypeOfVehicle;
}

Vehicle::~Vehicle()
{
	
	delete[] CompanyName;
	delete[]TypeOfVehicle;
	delete[] color;
	
}