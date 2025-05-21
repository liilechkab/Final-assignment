
//file containing interface for Airport class
#ifndef _Airport_
#define _Airport_
#include <string>
#include <vector>
#include <functional>
#include <set>

#include "Aircraft.h"
#include "Commercial.h"
using namespace std;

class Airport {
    private: //data member variables declared here
        string AirportName;
		vector<Aircraft> items; //reference to a vector of Aircraft objects - implements the composition relationship between the Airport & Aircraft classes
		set<Aircraft> itemsSet; //lab7-part1: set is an associative container that contains a sorted set of unique objects
        const int maxNofAircraft = 10;//lab4 - part4: declaring a constant variable, this variable will be initalised in the constructor initializer list in the Airport.cpp file
		static const int maxNofComm = 10;
		

    public: //data member functions declared here
        Airport(string, int);
		
		string getAirportName();
		void setAirportName(string n);

		void addAircraft(Aircraft a);
		void addCommercial(Commercial cm);

		void sortAirccraft(); //Lab5
		void sortAircraftByDefault(); //Lab5
		void sortAircraftByDeparture(); //Lab5
		void sortAircraftByName(); //Lab5
		
		void displayDetails();
		void findItemInVector(Aircraft a); //This function will use the std::find algorithm but as it uses the == operator for comparison it requires the equality opeartor (==) be overloaded in the Aircraft class
		void findItemInSet(Aircraft a); //lab7-part3

		void removeItemFromVector(Aircraft a);
		void removeItemFromSet(Aircraft a); //lab7-part3
		void displayVectorDetails();
		void displaySetDetails(); //lab7-part2

};

#endif /* _Airport_ */

