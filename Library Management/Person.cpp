#include "Person.h"

Person::~Person(){}
Person::Person(){}

Person::Person(Name n, Address a, string s,string p)
{
	name = n;
	address = a;
	school = s;
	phoneNumber = p;
}

Person::Person(string firstName, string lastName)
{
	this->name.firstName = firstName;
	this->name.lastName = lastName;
}

Person::Person(string firstName, string lastName, string phoneNumber):Person(firstName, lastName)
{
	
	this->phoneNumber = phoneNumber;
}

Person::Person(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode):Person(firstName, lastName, phoneNumber)
{
	this->address.streetAdress = streetAdress;
	this->address.city = city;
	this->address.state = state;
	this->address.zipCode = zipCode;
}

Person::Person(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode, string school):Person(firstName, lastName, phoneNumber, streetAdress, city, state, zipCode)
{
	this->school = school;
}

void Person::setName(string firstName, string lastName)
{
	this->name.firstName = firstName;
	this->name.lastName = lastName;
}

void Person::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Person::setAddress(string streetAdress, string city, string state, string zipCode)
{
	this->address.streetAdress = streetAdress;
	this->address.city = city;
	this->address.state = state;
	this->address.zipCode = zipCode;
}

void Person::setSchool(string school)
{
	this->school = school;
}
