#pragma once
#include "Person.h";
#include "Book.h";

class Member:public Person
{
private:
	int id = 0;
	string loginPassword;
	
public:
	vector <Book> borrowBook;
	~Member();
	Member();
	Member(string firstName, string lastName);
	Member(string firstName, string lastName, string phoneNumber);
	Member(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode);
	Member(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode, string school);
	Member(Name n, Address a, string s, string p, int i) :Person(n, a, s, p) { id = i; };


	int getId() { return id; }
	string getPassword() { return loginPassword; }

	void setId(int id);
	void setPassword(string password);
};

