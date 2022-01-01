#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"
#include "Array.h"
#include "Part.h"
#include "Aircraft.h"

using namespace std;

class Airline{

	public:
		Airline();
		Airline(const string& n);
		~Airline();
		
		//addAircraft creates a *new* aircraft and adds it to the Array of Aircraft* aircraft
		void addAircraft(const string&, const string&);

		//addPart creates a FH_part if FH_inspect is non-zero and all other parameters are 0
		//addPart creates an IT_part if IT_inspect is non-zero and all other parameters are 0
		//addPart creates an FHIT_Part if both flags are non-zero
		void addPart(const string& part, int fh_inspect, int it_inspect);

		//takeFlight gets the aircraft with Registration reg and calls Aircraft::takeFlight(hours)
		//which adds hours to the aircraft's flightHours
		void takeFlight(const string& reg, int hours);

		void printAircraft();
		void printParts();

		//inspectionReport calls the Aircraft::inspectionReport function for each Aircraft in aircraft
		void inspectionReport(const string& reg, Date& d);

		//install attemps to add a new part to an aircraft.
		//if the registration does not match with any aircraft or if the part name does not match
		//any of the Parts in part then false is returned
		bool install(const string&, const string&, Date& d);
		

	private:
		string name;
		Array<Part*> parts;
		Array<Aircraft*> aircraft;
		
		//getters
		Aircraft* getAircraft(const string& reg);
		Part* getPart(const string& n);


};







#endif

