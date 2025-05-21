//This file contains the implementation code for the NonCom class data member functions
#include "NonCom.h"

#include <iostream>
#include <string>

using namespace std;

int NonCom::nofNonCom = 0;

NonCom::NonCom(string p, int d, float v) : Aircraft(p, d)
{
	volume = v;
}

NonCom::NonCom(string p) : Aircraft(p){
	nofNonCom++;
}

int NonCom::getNofNonCom() {
	return nofNonCom;
}
void NonCom::setVolume(float v)
{
	if (v < 0 || v > 6000){
		cout<<"volume should be between 0 and 6000 kg"<<endl;
	} else {
		volume = v;
	}
}

float NonCom::getVolume()
{
	return volume;
}

void NonCom::display() {
	cout<<"NonCom '"<<getPilot()<< "Volume: " << getVolume() << " kg" <<endl;
}

