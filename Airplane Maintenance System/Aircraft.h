#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"
#include "Part.h"
#include "Array.h"

using namespace std;

class Aircraft{
	friend ostream& operator<<(ostream&, Array<Part*>&);
	public:
		Aircraft();
		Aircraft(const string& type, const string& registration);
		~Aircraft();

		string getRegistration();
		
		//install(Part*, Date&) adds a Date& to the Part* and then adds the Part* to the array of 
		//Parts parts		
		void install(Part*, Date&);

		//takeFlight(int hours) increases the flightHours of this Aircraft by hours
		void takeFlight(int hours);

		//inspectionReport calls the part->inspection() function for every part in Parts
		//If the part requires inspection (as determined by the respective part->inspection() function
		//then a pointer to the part is added to output
		void inspectionReport(Date& d, Array<Part*>* output);
		

	private:
		string type;
		string registration;
		int flighthours;
		Array<Part*> parts;

};

#endif
