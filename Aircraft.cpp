//This file contains the implementation code for the Aircraft class data member functions
#include "Aircraft.h"

#include <iostream>
#include <string>

using namespace std;


int Aircraft::nbAircraft = 0; //lab4 - part5: initialising the static variable


Aircraft::Aircraft() { 
	nbAircraft++;
	
}

Aircraft::Aircraft(string p) : pilot(p) {
	nbAircraft++;
	
}


Aircraft::Aircraft(string p, int n) : pilot(p), number(n) {
	nbAircraft++;
	//nbAircraftTest=0;
}


Aircraft::Aircraft(string p, int d,int n, bool s) : pilot(p), number(n), departure(d), security(s){
	nbAircraft++;
	//nbAircraftTest=0;

}

Aircraft::Aircraft(string p, int d,int n, bool s, string dt ) : pilot(p), number(n), departure(d), security(s), destination(dt){
	nbAircraft++;
	//nbAircraftTest=0;

}

string Aircraft::getPilot() const {
	return pilot;
}

void Aircraft::setPilot(string p) {
	pilot = p;
}

int Aircraft::getDeparture() const {
	return departure;
}

void Aircraft::setDeparture(int d) {
	departure = d;
}

Aircraft:: ~Aircraft() { };

void Aircraft::displayDetails() const {
	cout<<"Aircraft '"<<getPilot() <<"' has departure "<<getDeparture()<<endl;
}

//non member functions (notice they do not have 'Aircraft::' in front of their names) implemented here - used for overloading operators
bool operator==(Aircraft pl1, Aircraft pl2) {
   return (pl1.getPilot()==pl2.getPilot() && pl1.getDeparture()==pl2.getDeparture());
}

bool operator!=(Aircraft pl1, Aircraft pl2) {
    return !(pl1==pl2);
}

bool operator<(Aircraft pl1, Aircraft pl2) {
    return (pl1.getPilot()<pl2.getPilot());
	//return (pl1.getDeparture()<pl2.getDeparture());
}

bool operator>(Aircraft pl1, Aircraft pl2) {
   return (pl1.getPilot()>pl2.getPilot());
}

ostream& operator<< (ostream &cout, Aircraft pli) {
	cout<<"Using overloaded ostream operator - Aircraft '"<<pli.getPilot() <<"' has Departure "<<pli.getDeparture()<<endl;
    return cout;
}



