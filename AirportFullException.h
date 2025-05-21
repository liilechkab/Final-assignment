#ifndef AIRPORTFULLEXCEPTION_H_
#define AIRPORTFULLEXCEPTION_H_

#include <iostream>
#include <exception>
using namespace std;

//Lab8 - Part 3 : user defined exception class inheriting from exception class
class AirportFullException : public exception{
public:
	  virtual const char* what() const throw() { //overridden what() function (http://www.cplusplus.com/doc/tutorial/exceptions/)

		  return "Airport is full";
	  }

};

#endif /* AirportFULLEXCEPTION_H_ */
