#pragma once
#include <string>
using namespace std;


struct Name
{
	string firstName;
	string lastName;
};
struct Address {
	string streetAdress;
	string city;
	string state;
	string zipCode;
};
class Person
{
private:


	Name name;
	string phoneNumber;
	Address address;
	string school;

public:



	~Person();
	Person();
	Person(Name n, Address a, string school,string phoneNumber);
	Person(string firstName, string lastName);
	Person(string firstName, string lastName,string phoneNumber);
	Person(string firstName, string lastName, string phoneNumber, string streetAdress,string city,string state,string zipCode);
	Person(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode,string school);

	void setName(string firstName, string lastName);
	void setPhoneNumber(string phoneNumber);
	void setAddress(string streetAdress, string city, string state, string zipCode);
	void setSchool(string school);

	Name getName() { return name; }
	string getPhoneNumber() { return phoneNumber; }
	Address getAddress() { return address; }
	string getSchool() { return school; }

	

	//virtual void printDetails() = 0;

};

