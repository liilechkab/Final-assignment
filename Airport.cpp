#include "Airport.h"
#include "AirportFullException.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

Airport::Airport(string n, int nofAircraft) : maxNofAircraft(nofAircraft) {
	setAirportName(n);
}

string Airport::getAirportName() {
	return AirportName;
}

void Airport::setAirportName(string n) {
	AirportName = n;
}

void Airport::addAircraft(Aircraft e) {
	if (items.size() <= maxNofAircraft) {
    	items.push_back(e);
    } else {
    	//cout<<"Airport is full"<<endl;
		AirportFullException pfe; //lab8 - part2: create a custom exception object
    	throw pfe;

    }
}

void Airport::addCommercial(Commercial cm) {
	if (itemsSet.size() <= maxNofComm) { 
    	itemsSet.insert(cm);
    } else {
    	cout<<"Airport is full"<<endl;
    }
}

//Lab5: - this is a helper function used by the sortAirport function
bool orderByDeparture(Aircraft item1, Aircraft item2){ //this function determines how Aircraft objects are compared
	return (item1.getDeparture() < item2.getDeparture());
}

bool orderByName(Aircraft item1, Aircraft item2){ //this function determines how Aircraft objects are compared
	return (item1.getPilot() < item2.getPilot());
}

//Lab5: - this function uses the orderByDeparture helper function to sort the object in the 'items' vector
void Airport::sortAircraftByDeparture() {
	cout<<"sorting Aircraft"<<endl;
	sort(items.begin(), items.end(), orderByDeparture);
}

void Airport::sortAircraftByName() {
	cout<<"sorting Airport"<<endl;
	sort(items.begin(), items.end(), orderByName);
}

//Lab5: - this function requires that the < operator is overloaded in the class of the objects stored in the 'items' vector (i.e. in the Aircraft class)
void Airport::sortAircraftByDefault() {
	cout<<"sorting Aircraft"<<endl;
	sort(items.begin(), items.end());
}

void Airport::displayDetails() {
	cout << "The " <<items.size() <<" Aircraft(s) in the Airport are: " <<endl;
	for (int i=0; i<items.size(); i++) {
		//items[i].display();
		cout<<items[i]; //uses the overloaded ostream operator in the class of the objects stored in the 'items' vector (i.e. in the Aircraft class)
	}
  	std::cout << '\n';
}

void Airport::findItemInVector(Aircraft s) {
	/*bool found = false;
	// Iterate over all elements in Vector
	for (Aircraft pli : itemsVector) {
	    if (pli == s) { //this requires that the == operator is overloaded in the Aircraft class
	        found = true;
	        break;
	    }
	    cout << pli << endl;
	}
	if(found) {
	    cout << "Element Found" << endl;
	} else {
	    cout << "Element Not Found" << endl;
	}*/

	auto it = find(items.begin(), items.end(), s); //Reference http://www.cplusplus.com/reference/algorithm/find/
	if (it != items.end()) {
		cout<<s.getPilot()<<" item is in the Airport - details are :"<<endl;
		cout<<*it;
	} else {
		cout<<s.getPilot()<<" item is not in this Airport"<<endl;
	}
}

void Airport::findItemInSet(Aircraft s) { //Part2
	/*bool found = false;
	// Iterate over all elements in Set
	for (Aircraft pli : itemsSet) {
	    if (pli == s) { //this requires that the == operator is overloaded in the Aircraft class
	        found = true;
	        break;
	    }
	    cout << pli << endl;
	}

	if(found)
	    cout << "Element Found in set" << endl;
	else
	    cout << "Element Not Found in set" << endl;
   */
	//set<Aircraft>::iterator it = find(itemsSet.begin(), itemsSet.end(), s);
	auto it = find(itemsSet.begin(), itemsSet.end(), s);
	if (it != itemsSet.end()) {
		cout<<"Aircraft details found are :"<<endl;
		cout<<*it;//Note: because set<T>::iterator is const the get functions that the overloaded ostream operator calls MUST also be declared const
		it->displayDetails() ; //Note: because set<T>::iterator is const the display function MUST be declared const
	} else {
		cout<<s.getPilot()<<" item is not in this Airport"<<endl;
	}

}

void Airport::displayVectorDetails() {
	cout << "The " <<items.size() <<" Aircraft(s) in the Airport vector are: " <<endl;
	/*for (int i=0; i<items.size(); i++) {
		cout<<items[i]; //there is no subscript operator for a Set so this will not work
	}*/
	/*for (Aircraft pli : items) {
		cout << pli << endl;
	}*/
	for(auto it = items.begin(); it != items.end(); it++) {
	  cout<<*it;
	}
}

void Airport::displaySetDetails() {
	cout << "The " <<itemsSet.size() <<" Aircraft(s) in the Airport set are: " <<endl;
	/*for (int i=0; i<itemsSet.size(); i++) {
		cout<<itemsSet[i]; //there is no subscript operator for a Set so this will not work
	}*/
	/*for (Aircraft pli : itemsSet) {
	    cout << pli << endl;
	}*/
	/*for(auto it = itemsSet.begin(); it != itemsSet.end(); it++) { //lab7-part2 - using iterators to traverse a set of items
	  cout<<*it;
	}*/

	std::set<Aircraft>::const_iterator it; // declare an iterator
	    it = itemsSet.cbegin(); // assign it to the start of the set
	    while (it != itemsSet.cend()) // while it hasn't reach the end
	    {
	        std::cout << *it << " "; // print the value of the element it points to
	        ++it; // and iterate to the next element
	    }
}

void Airport::removeItemFromVector(Aircraft s) {
	cout<<"Removing details for Aircraft " <<s.getPilot()<<endl;
	items.erase(remove(items.begin(), items.end(), s), items.end()); //c.f. https://www.freecodecamp.org/news/how-to-remove-elements-from-a-container-in-c/ // @suppress("Invalid arguments")
}

void Airport::removeItemFromSet(Aircraft s) {
	cout<<"Removing details for Aircraft " <<s.getPilot()<<endl;
	itemsSet.erase(s); //Part1: note erase is used here to remove an element from the set
					   //reference: https://www.cplusplus.com/reference/set/set/erase/
}


