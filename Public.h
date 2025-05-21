
#ifndef PUBLIC_H_
#define PUBLIC_H_
#include "Owner.h"

class Public : public Owner { //lab2 - Part2: implements the Inheritance association between the Owner and Public classes
	private: //private data member variables
		int nofMember;
	public:
		Public();
		int getNofPublicMember();
		void setNofPublicMember(int nofM);
		float calcWages(); //lab3 - part4 : this function overrides the abstract calcWages function in its parent (Owner) class
		void display(); //lab3 - part1: this function overrides the display function in its parent (Owner) class
};

#endif /* Public_H_ */
