#include<iostream>
#include<string>
using namespace std;
#include "Customer.h"
Customer::Customer()
{
	this->Person::Person();
	this->MechanicID = "";
	this->app.hours = -1;
	this->app.min = -1;
}
Customer::Customer(string str, Appointment moment)
{
	Customer(str, "", 0, "", moment);

}
Customer::Customer(string nam,string id, int ag, string mid, Appointment temp)
{
	this->Person::Person(nam,id,ag);
	this->MechanicID = mid;
	this->app = temp;
}
void Customer::PrintInfo() const
{
	cout << "Customer Name is " << this->GetName() << endl;
	cout << "Customer Age is " << this->GetAge() << endl;
	cout << "Customer ID is " << this->GetID() << endl;
	if (this->GetApp().hours == -1)
		cout << "No Mechanic was Available at the time chosen " << endl<<endl;
	else
	{
		cout << "Customer has an Appointment at " << this->GetApp().hours << ":" << this->GetApp().min <<endl;
		cout << "The Mechanic Assigned to this customer has ID " << this->GetMID() << endl<<endl;
	}
}
void Customer::SetMID(string id)
{
	this->MechanicID = id;
}
void Customer::SetApp(Appointment test)
{
	this->app = test;
}
string Customer::GetMID() const
{
	return this->MechanicID;
}
Appointment Customer::GetApp() const
{
	return this->app;
}
bool Customer::operator<(const Customer &compare) const
{
	if (this->GetApp().hours < compare.GetApp().hours)
	{
		return true;
	}
	else if (this->GetApp().hours > compare.GetApp().hours)
	{
		return false;
	}
	else if (this->GetApp().min >= compare.GetApp().min)
	{
		return false;
	}
	else if (this->GetApp().min < compare.GetApp().min)
	{
		return true;
	}
}
bool Customer::operator>(const Customer &compare) const
{
	if ((*this < compare) || ((this->GetApp().hours == compare.GetApp().hours) && (this->GetApp().min == compare.GetApp().min)))
		return false;
	else
		return true;
}
bool Customer::operator==(const Customer &compare) const
{
	if ((this->GetApp().hours == compare.GetApp().hours) && (this->GetApp().min == compare.GetApp().min))
		return true;
	else
		return false;
}
