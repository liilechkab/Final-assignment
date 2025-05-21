
#include "Public.h"
#include <iostream>
#include <string>

using namespace std;

Public::Public() {
	// TODO Auto-generated constructor stub
}

int Public::getNofPublicMember() {
	return nofMember;
}

void Public::setNofPublicMember(int nofM) {
	if (nofM < 0){
		cout<<" the number of members can not be inferior than 0 "<<endl;
	} else {
		nofMember = nofM;
	}

}

float Public::calcWages() {
	cout<<"calling calcEarnings function defined in Public class"<<endl;
	return Owner::getEarnings()/nofMember;}

void Public::display() { //this function overrides the function with the same signature (name, number, order and type of parameters) in the Owner class
	cout<<"calling display function defined in Public class"<<endl;
	cout<<getOwnerName()<<" Public has : "<< getNofPublicMember() <<" members "<<endl;
}
