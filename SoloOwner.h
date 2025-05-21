//file containing interface for SoloOwner class
#ifndef _SOLOOWNER_
#define _SOLOOWNER_
#include <string>
#include "Owner.h"
using namespace std;

class SoloOwner : public Owner { //lab2 - Part2: implements the Inheritance association between the Owner and SoloOwner classes

private: //private data member variables
	float fee;

public: //data member functions declared here

	SoloOwner(); //default SoloOwner constructor
	SoloOwner(string ); //user defined SoloOwner overloaded constructor
	SoloOwner(string, bool); //2nd user defined SoloOwner overloaded constructor

	int getFee();
	void setFee(float);
	void display(); //lab3 - part1: this function overrides the display function in its parent (Owner) class

};
#endif /* _SOLOOwner_ */

