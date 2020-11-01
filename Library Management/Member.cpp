#include "Member.h"

Member::~Member()
{
}

Member::Member() { loginPassword = "password"; }

Member::Member(string firstName, string lastName) :Person(firstName, lastName) {}

Member::Member(string firstName, string lastName, string phoneNumber) : Person(firstName, lastName, phoneNumber) {}

Member::Member(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode) : Person(firstName, lastName, phoneNumber, streetAdress, city, state, zipCode) {}

Member::Member(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode, string school) : Person(firstName, lastName, phoneNumber, streetAdress, city, state, zipCode, school) {}

void Member::setId(int id) { this->id = id; }

void Member::setPassword(string password) { this->loginPassword = password; }