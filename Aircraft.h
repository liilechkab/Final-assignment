//file containing interface for Aircraft class
#ifndef _Aircraft_
#define _Aircraft_

#include <string>
using namespace std;

class Aircraft {
private: //data member variables declared here

int number;

string destination;
bool security;
//int nbAircraftTest;// //lab4 - part5: declaring a static variable

protected: 
string pilot;
int departure;

public: //data member functions declared here
    static int nbAircraft;
    Aircraft();
    Aircraft(string pilot);
    Aircraft(string, int);
    Aircraft(string, int, int, bool); // user-defined overloaded constructor with 4 parameters
    Aircraft(string, int, int, bool, string);
    virtual ~Aircraft();

  void setPilot(string);
  void setDeparture(int);
  void setNumber(int);
  void setSecurity(bool);
  void setDestination(string);
  
  string getPilot() const;
  int getDeparture() const;
  int getNumber();
  bool getSecurity();
  string getDestination();

  virtual void displayDetails() const;
};

//Lab5 - overloaded equality and inequality operators implemented as normal functions
bool operator==(Aircraft, Aircraft);
bool operator!= (Aircraft, Aircraft);
bool operator<(Aircraft, Aircraft);
bool operator>(Aircraft, Aircraft);

//Lab5 - overloaded ostream operator implemented as normal functions
ostream& operator<< (ostream &cout, Aircraft pli);

#endif /* _Aircraft_ */




