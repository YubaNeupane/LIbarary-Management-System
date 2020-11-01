	#pragma once
	#include "Person.h"
	#include <iostream>
	using namespace std;

	class Librarian:public Person
	{
	private:
		int id=0;
		string loginPassword;

	public:
		~Librarian();
		Librarian();
		Librarian(Name n, Address a, string s, string p, int i) :Person(n, a, s, p) { id = i; };

		Librarian(string firstName, string lastName);
		Librarian(string firstName, string lastName, string phoneNumber);
		Librarian(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode);
		Librarian(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode, string school);

		int getId() { return id; }
		string getPassword() { return loginPassword; }

		void setId(int id);
		void setPassword(string password);

		void printDetials() {
			cout << "Hello" << endl;
		}

	};
