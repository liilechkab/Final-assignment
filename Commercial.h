//file containing interface for COMMERCIAL class
#ifndef _COMMERCIAL_
#define _COMMERCIAL_
#include <string>
#include "Aircraft.h"
#include "Owner.h"

//class Owner; 
using namespace std;

class Commercial : public Aircraft { //implements the Inheritance association between the Aircraft and Commercial classes
private: 

	//Owner owner;//lab4 - Part1: implements a 1:1 aggregation relationship Aggregation relationship between the Commercial and Owner classes
//data member variables declared here
	int passenger;
	Owner *ownPtr; //reference to Owner class which implements the association relationship between the Commercial & Owner classes

    static int nofCommercial; //lab4 - Part3

public: //data member functions declared here
    Commercial(string pilot);
	Commercial(const string pilot,int departure, Owner& owner); //user-defined overloaded constructor
	//Commercial(string, int, Owner);  user-defined overloaded constructor with 3 paramters

	Commercial(const Commercial& source); //user-defined copy constructor
    ~Commercial();                  // user-defined copy destructor
    Commercial &operator=(Commercial &source); // user-defined assignment operator

  
  void setPassenger(int);
  int getPassenger() const;
  void setOwner(Owner);
  Owner getOwner();
	

int static getNofCommercial();

void displayCommercialDetails();
void displayCommercialDetails(string pilot);


	//Lab5 - overloaded comparison operators implemented as friend functions
	//friend bool operator>= ( Commercial,  Commercial);
	//friend bool operator<= ( Commercial,  Commercial);
	//friend ostream& operator<< (ostream&, Commercial );

	//Lab5 - overloaded comparison operators implemented as friend functions
	//friend bool operator <(Commercial, Commercial); //lh operand is passed implicitly to the overloaded < operator
	//friend bool operator >(Commercial, Commercial);

	//Lab5 - overloaded comparison operators implemented as member functions
	bool operator <(Commercial c); //lh operand is passed implicitly to the overloaded < operator
	bool operator >(Commercial c);

	//Lab5 - overloaded ostream operator implemented as friend functions
	friend ostream& operator<< (ostream&, Commercial );

	//friend bool operator==(Commercial, Commercial);
	//friend bool operator!= (Commercial, Commercial);

};
//Lab5 - overloaded equality and inequality operators implemented as normal functions
bool operator==(Commercial, Commercial);
bool operator!= (Commercial, Commercial);


#endif /* _COMMERCIAL_ */
