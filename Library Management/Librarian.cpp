#include "Librarian.h"

Librarian::~Librarian(){}

Librarian::Librarian() { loginPassword = "password"; }

Librarian::Librarian(string firstName, string lastName):Person(firstName, lastName){}

Librarian::Librarian(string firstName, string lastName, string phoneNumber):Person(firstName,lastName,phoneNumber){}

Librarian::Librarian(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode) : Person(firstName, lastName, phoneNumber,  streetAdress,  city,  state,  zipCode){}

Librarian::Librarian(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode, string school):Person(firstName, lastName, phoneNumber, streetAdress, city, state, zipCode, school){}



void Librarian::setId(int id){this->id = id;}

void Librarian::setPassword(string password){loginPassword = password;}
