//This file contains the implementation code for the Commercial class data member functions
#include "Commercial.h"
#include "Owner.h"
#include <iostream>
#include <string>

using namespace std;

int Commercial::nofCommercial = 0;

Commercial::Commercial(const string p) : Aircraft(p) {
	setPilot(p);
	nofCommercial++;
}

Commercial::Commercial(const string p, int d, Owner& o) : Aircraft(p, d), ownPtr(new Owner(o))
{ // lab3 - part2 : constructor that uses member initializer list to call the parent class constructor from the child class
}

Commercial::Commercial(const Commercial &objBeingCopied) : Aircraft(objBeingCopied) { // user-defined copy constructor for deep coyping of pointer fields
	cout << "user-defined copy constructor, object being copied is " << objBeingCopied.getPilot() << endl;
	// deep copy the pointer variable (copy the values the pointer points to and not the pointer value itself)
	if (objBeingCopied.ownPtr)
	{
		ownPtr = new Owner(); // allocate dynamic memory from the heap for our copy
		*ownPtr = *(objBeingCopied.ownPtr);
	}
	else {
		ownPtr = 0;
	}
	nofCommercial++;
}

Commercial &Commercial::operator=(Commercial &objBeingCopied) // over-loaded assignment operator for deep coyping of pointer fields
{
	cout << "overloaded assignment operator, object being copied is " << objBeingCopied.getPilot() << endl;
	// check for self-assignment to avoid copying an object to itself e.g. c1 = c1;
	if (this == &objBeingCopied) 
		return *this; //skip the rest of the function as there is no need for it

    // deallocate any memory that the object being updated is holding!
	delete ownPtr;
	// shallow copy of the variable values that are not pointers values
	this->pilot = objBeingCopied.getPilot();
	this->departure = objBeingCopied.departure;
	// deep copy the pointer variable (copy the values the pointer points to and not the pointer value itself)
	if (objBeingCopied.ownPtr) //check that the pointer for the object being copied has a value
	{
		ownPtr = new Owner(); // allocate new memory to hold the Owner details for the object being updated
		*ownPtr = *objBeingCopied.ownPtr;
	}
	else {
		ownPtr = 0;
	}
    return *this;
}

Commercial::~Commercial() { //user defined destuctor to handle deallocation of dynamic memory
	cout<<"calling destructor for "<< this->getPilot()<<endl;
	nofCommercial--; //decrement the counter
	if (ownPtr != nullptr)
	{
		delete ownPtr;	  // Release memory allocated for the Owner object
		ownPtr = nullptr; // Set the pointer to null to avoid double deletion
	}
}


void Commercial::setOwner(Owner o) {
	ownPtr = new Owner();
	*ownPtr = o;
}
Owner Commercial::getOwner() {
	return *ownPtr;
}


int Commercial::getNofCommercial() {
	return nofCommercial;
}

void Commercial::setPassenger(int pgr) {
    if (pgr < 0 || pgr > 600){
		cout<<"the number of passagers should be between 0 and 600 "<<endl;
	} else {
		passenger = pgr;
	}
}

int Commercial::getPassenger() const {
    return passenger;
}

/*Overloading using member functions*/

bool Commercial::operator>(Commercial c) {
	cout<<"using overloaded > operator"<<endl;
	return  this->getDeparture() > c.getDeparture();
}

bool Commercial::operator<(Commercial c) {
	return getDeparture()< c.getDeparture();
}

/*Overloading using friend functions*/
/*bool operator>(Commercial c1, Commercial c2) {
	cout<<"using overloaded > operator as a friend function"<<endl;
	return  c1.getDeparture() > c2.getDeparture();
}

bool operator<(Commercial c1, Commercial c2) {
	return  c1.getDeparture() < c2.getDeparture();
}*/
/*
bool operator<=(Commercial c1, Commercial c2) {
	return c1.getDeparture()<= c2.getDeparture();
}
bool operator>=(Commercial c1, Commercial c2) {
	//return c1.getDeparture()<= c2.getDeparture();
	return c1.getDeparture()<= c2.getDeparture();
}

*/
bool operator==(Commercial c1, Commercial c2) {
   //return (c1.getName()==c2.getName() && c1.getDeparture()==c2.getDeparture());
	return (c1.getPassenger()==c2.getPassenger());
}

bool operator!=(Commercial c1, Commercial c2) {
    return !(c1==c2);
}

ostream& operator<< (ostream &cout, Commercial c) {
	cout<<"Using overloaded ostream operator - Commercial '"<<c.getPilot() <<"' has Departure "<<c.getDeparture()<<endl;
    return cout;
}

void Commercial::displayCommercialDetails() {
	cout<<"Name of pilot : "<<getPilot() <<" commercial owned by "<<(getOwner()).getOwnerName()<<endl;
}

