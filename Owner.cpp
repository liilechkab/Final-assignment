//This file contains the implementation code for the Owner class data member functions
#include "Owner.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Owner::Owner() {
	//cout<<"calling default Owner constructor"<<endl;
	setOwnerName("");
	name="Elias :)";
}
Owner::Owner(const string &name) {
    this->name = name;
    this->earnings = 0.0f;
}
Owner::Owner(const string &name, float earnings) {
	this->name = name;
	this->earnings = earnings;
}


string Owner::getOwnerName() const { 
	return name;
 }

float Owner::getEarnings() const { 
	return earnings; 
}

void Owner::setOwnerName(const string& name) {
	this->name = name;
}

void Owner::setEarnings(float er) {
	earnings = er;
}


float Owner::calcWages() {
	cout<<"calling calcEarnings function defined in Owner class"<<endl;
	return earnings;
}

void Owner::display() {
	cout<<"calling display function defined in Owner class"<<endl;
	cout<<"Owner "<<getOwnerName() <<endl;
}
// Overload the ostream operator to write Owner object to a stream (e.g., file).
ostream &operator<<(ostream &os, const Owner &owner)
{
	os << owner.getOwnerName() << "," << owner.getEarnings();
	return os;
}

// Overload the istream operator to read Owner object from a stream (e.g., file).
istream &operator>>(istream &is, Owner &owner)
{
	string line;
	getline(is, line);
	stringstream ss(line);
	string token;

	getline(ss, token, ',');
	string name = token;

	/*getline(ss, token, ',');
	int nofSingles = 0;
	try
	{
		nofSingles = stoi(token);
	}
	catch (const invalid_argument &e)
	{
		// Handle error, e.g., log it, set a default value, or throw.
		nofSingles = 0;
	}
		*/

	getline(ss, token, ',');
	float earnings = 0;
	try
	{
		earnings = stod(token);
	}
	catch (const invalid_argument &e)
	{
		earnings = 0;
	}
	owner = Owner(name, earnings);
	return is;
}
