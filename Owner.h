//file containing interface for Owner class
#ifndef _OWNER_
#define _OWNER_
#include <string>
#include <iostream>
using namespace std;

class Owner {

	private: //private data member variables
	    float earnings; 
		friend std::ostream &operator<<(std::ostream &os, const Owner &owner);
		friend std::istream &operator>>(std::istream &is, Owner &owner);
	protected:
		string name;

	public: //data member functions declared here
		Owner(); // User defined default (parameterless) constructor
		Owner(const string &name); //lab1: part4 - user-defined constructor
		Owner(const string &name, float); //lab1: part4 - user-defined constructor
		Owner(float, const string &name); //lab1: part4 - user-defined constructor


		//mutator (set) methods
		void setOwnerName(const string& name);
		
		//accessor (get) methods
		string getOwnerName() const;
		float getEarnings() const;
		void setEarnings(float er);
		virtual float calcWages();
		virtual void display(); //lab3 - part3: the overridden function is now marked as virtual to enable late binding
};
#endif /* _Owner_ */

