//This file contains the implementation code for the SoloOwner class member functions
#include "SoloOwner.h"
#include <iostream>
using namespace std;

SoloOwner::SoloOwner()  {
	//cout<<"calling default SoloOwner constructor"<<endl;
	//initialise the variables for the class
	setOwnerName("");
	setFee(0);
}

SoloOwner::SoloOwner(string n) : Owner(n) { //lab3 - part2: SoloOwner constructor - it calls the user defined parent class constructor explicitly in this initialization list
	//cout<<"calling user defined overloaded SoloOwner constructor"<<endl;

	fee=0;
}



/*
SoloOwner::SoloOwner(string n//, bool b) : Owner(n)//, hasBackingPublic(b)
 /*{ //using initialization list for constructor code
	PublicFee=0;
}
bool SoloOwner::getHasBackingPublic() {
	return hasBackingPublic;
}

void SoloOwner::setHasBackingPublic(bool ibb) {
	hasBackingPublic = ibb;
}
*/
int SoloOwner::getFee() {
	return fee;
}

void SoloOwner::setFee(float f) {
	fee = f;
}


void SoloOwner::display() { //this function overrides the function with the same signature (name, number, order and type of parameters) in the Owner class
	cout<<"calling display function defined in SoloOwner class"<<endl;
	Owner::display();
	//cout<<" has backing Public? : "<<getHasBackingPublic()<<endl;
}
