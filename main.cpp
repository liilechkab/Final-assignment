#include <iostream>
#include <fstream>
#include "SoloOwner.h"
#include "Public.h"
#include "Commercial.h"
#include "NonCom.h"
#include "Airport.h"
#include "AirportFullException.h" //lab8 - part2
#include <vector>
#include <algorithm>
#include <stdexcept> // Include for exceptions
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	// Read Owner objects from a file at the start of the program.
	vector<Owner> owners;
	ifstream inFile("owners.txt");
	if (inFile.is_open())
	{
		Owner owner;
		try
		{
			while (inFile >> owner)
			{ // Read Owners from the file.
				owners.push_back(owner);
			}
		}
		catch (const runtime_error &e)
		{
			cerr << "Error reading from file: " << e.what() << endl;
			// Consider if you want to continue processing or exit.
		}
		inFile.close();
		cout << "Read " << owners.size() << " owners from file.\n";
	}
	else
	{
		cerr << "Could not open the input file: owners.txt" << endl;
		// Consider exiting the program if the input file is essential.
		return 1; // Return an error code.
	}

	// Create some Owner objects.
	Owner owner1("Jimi Hendrix", 1000000);
	Owner owner2("The Beatles", 5000000);
	Owner owner3("Bob Dylan", 2500000);
	owners.push_back(owner1);
	owners.push_back(owner2);
	owners.push_back(owner3);

	for (vector<Owner>::const_iterator it = owners.begin(); it != owners.end(); ++it) {
		const Owner &owner = *it;
		cout << "Name: " << owner.getOwnerName()
			 << ", Earnings: " << owner.getEarnings() << endl;
	}

	/*for (const Owner &owner : owners)
	{
		cout << "Name: " << owner.getName()
			 << ", Earnings: " << owner.getEarnings() << endl;
	}*/

	// Write Owner objects to a file at the end of the program.
	ofstream outFile("owners.txt");
	if (outFile.is_open())
	{
		for (vector<Owner>::const_iterator it = owners.begin(); it != owners.end(); ++it) {
			const Owner &owner = *it;
			outFile << owner << endl; // Use the overloaded << operator.
		}

		outFile.close();
		cout << "Wrote " << owners.size() << " owners to file.\n";
	}
	else
	{
		cerr << "Could not open the output file: owners.txt" << endl;
		// Consider exiting the program if the output file is essential.
		return 1; // Return an error code.
	}
	Commercial c1("Orlaith", 3,owner1); //create a commercial object, owner1
	c1.setDeparture(4);
	cout<<c1.getPilot()<<endl;
	cout<<c1;

	Commercial c4 = c1; //calls the copy constructor that uses deep copy 

	Commercial c3("Vincent",5, owner2);

	c3 = c1; //calls the overloaded assignment operator that uses deep copy

	Commercial c2("Elias",4, owner2);
	c2.setDeparture(2);
	SoloOwner so1("Tayor Swift");
	so1.display();//calls the display function from the Owner class

	SoloOwner so2("Ryan Gosgling");
	so2.display();//calls the display function from the Owner class

	Commercial c5("Demi Moore");
	c5.setOwner(so1);
	

	//Many algorithms use inbuilt operators behind the scenes
	//e.g. the sort algorithm uses the 'less than' ('<') operator
	//This code works fine by default - the vector of strings can be sorted without overloading the inbuilt operators
	cout<<"******************************"<<endl;
	cout<<"tests showing that sort algortihms work fine for string types"<<endl;
	vector<string> CommercialPilot;
	CommercialPilot.push_back("Elias");
	CommercialPilot.push_back("Gosling");
	CommercialPilot.push_back("Orlaith");
	cout<<"Commercials before they are sorted"<<endl;

	for (int i = 0; i < CommercialPilot.size(); i++)
	{
		cout << CommercialPilot[i] << endl;
	}
/*
	for (string s :  CommercialPilot) {
        cout << s <<endl;
    }
*/

	sort(CommercialPilot.begin(), CommercialPilot.end());
	cout << "sort algorithm is used to sort the list of Commercials based on their Pilot:" <<endl;
    /*for (string s :  CommercialPilot) {
        cout << s <<endl;
    }*/
	for (int i = 0; i < CommercialPilot.size(); i++)
	{
		cout << CommercialPilot[i] << endl;
	}
	/* Now for tests using our user defined types */
	Public b1;
	b1.setOwnerName("Ryanair"); //instantiate/create a Public object using the user defined constructor
	b1.display();//lab3 - part1: calls the display function from the Owner  class

	
	
	/* tests to compare two Commercial objects */
	cout<<"******************************"<<endl;
	cout<<"testing overloaded greater than ('>') operator for Commercial objects"<<endl;
	if (c1>c3) { //this will only work if the greater than ('>') operator has been overloaded in the Commercial class or in its parent class
		cout<<"c1 has a longer Departure than c3"<<endl;
	} else {
		cout<<"c3 has a longer Departure than c1"<<endl;
	}

	/* tests to compare two Commercial objects for equality*/
	cout<<"******************************"<<endl;
	cout<<"testing overloaded equality ('==') operator for Commercial objects"<<endl;
	if (c1==c2) { //this will only work if the equality ('==') operator has been overloaded in the Commercial class or in its parent class
		cout<<"c1 is equal to c2"<<endl;
	} else {
		cout<<"c2 is not equal to c1"<<endl;
	}

	/* tests to show the use of the overloaded less than ('<') operator with the STL sort algorithm */
	cout<<"******************************"<<endl;
	cout<<"testing that the sort algorithm works for Commercial objects - this requires that the less than ('<') operator is overloaded for Commercial objects"<<endl;	
	Airport pl1("Paula's Airport", 8);
	pl1.addAircraft(c1);
	pl1.addAircraft(c2);
	pl1.addAircraft(c3);
	cout<<"******************************"<<endl;
	cout<<"order before sorting based on the criteria specified in the overloaded less than ('<') operator"<<endl;
	pl1.displayDetails(); //order before sorting by name
	pl1.sortAircraftByDefault(); //uses the overloaded < operator in the Aircraft as the sorting criterion
	cout<<"******************************"<<endl;
	cout<<"order after sorting based on the overloaded less than ('<') operator: "<<endl;
	pl1.displayDetails();
	pl1.findItemInVector(c1);

	pl1.sortAircraftByDeparture(); //uses the overloaded < operator in the Aircraft as the sorting criterion
	cout<<"******************************"<<endl;
	cout<<"order after sorting by Departure: "<<endl;
	pl1.displayDetails();

	pl1.sortAircraftByName(); //uses the overloaded < operator in the Aircraft as the sorting criterion
	cout<<"******************************"<<endl;
	cout<<"order after sorting by name: "<<endl;
	pl1.displayDetails();

	/* tests to use the overloaded ostream ('<<') operator to print out a Commercial object details*/	
	cout<<"******************************"<<endl;
	cout<<"testing overloaded ostream ('<<') operator for a Commercial object"<<endl;
	cout<<c1; //this will only work if the ostream operator is overloaded for the Commercial class
	cout<<"Paula's 2nd Airport implemented with a set data structure"<<endl;


	Airport pl2("Paula's 2nd Airport implemented with a set data structure", 8);
	pl2.addCommercial(c2);
	pl2.addCommercial(c1);
	pl2.addCommercial(c1); //c1 will not be added to the set as a set cannot contain duplicate entries
					 	  //Note: Elements a and b are considered equal iff !(a < b) && !(b < a)
						  //so the operators < and > are used for checking for duplicates
						  //http://www.cplusplus.com/reference/set/set/insert/
	pl2.addAircraft(c3);
	pl2.findItemInSet(c1); //testing that the find algorithm works when item is in the Airport
	pl2.removeItemFromSet(c1);
	pl2.findItemInSet(c1); //testing that the find algorithm works when item is NOT in the Airport
	pl2.displaySetDetails();


	/*
	/*lab8 - part1*/
	/*
	Public b1;
	b1.setName("Ryanair"); //instantiate/create a Public object using the user defined constructor
	b1.display();//lab3 - part1: calls the display function from the Owner class
	try { //lab8 - part1
		cout<<"band wages are: " <<b1.calcWages()<<endl;
		cout<<"no exception"<<endl;
	} catch (string exceptionMessage) {
		cerr << exceptionMessage << endl;
	}
	try{//lab8 - part2
		cout<<b2.calcWages()<<endl; //this will result in an exception being raised but as it is caught it will not terminate the program
		cout<<"check if this line is executed if there is an exception"<<endl; //lab8 part2
	} catch(char const* exceptionMessage) {
		cout << exceptionMessage << endl; //prints exception message from Public class
	}*/
	//lab8 - part3
	try {
		pl1.addAircraft(c1);
		pl1.addAircraft(c2);
		pl1.addAircraft(c3);
	} catch (AirportFullException pfe) { //lab8 - part3: handling custom exception type AirportFullException
		cout<<pfe.what()<<endl;
		//cout<<"Airport is full"<<endl;
	} catch(...) { //lab8 - part3: this clause is executed if an exception that is not a AirportFullException exception is raised
		cout<<"an exception has occurred"<<endl;
	}
    cout<<" lab 8 exception handling code"<<endl;


	return 0;
}
