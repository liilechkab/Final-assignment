//file containing interface for NonCom class
#ifndef _NonCom_
#define _NonCom_
#include <string>
#include "Aircraft.h"
using namespace std;

class NonCom : public Aircraft { //implements the Inheritance association between the Aircraft and Commercial classes
private: //data member variables declared here
    float volume; // //lab4 - part5: declaring a static variable
    static int nofNonCom;

public: //data member functions declared here
    NonCom(string pilot);
    NonCom(string, int); // user-defined overloaded constructor with one parameter
    NonCom(string, int, float);

    void setVolume(float);
    float getVolume();

    int getNofNonCom();

    void display();
};
#endif /* _NonCom_ */
