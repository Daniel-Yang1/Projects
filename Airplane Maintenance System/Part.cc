#include "Part.h"

ostream& operator<<(ostream& out, Part* p){
	out << p->getName() << endl;
	return out;
}

Part::Part(){
	name = "temp";
	flighthours = 0;
}

Part::Part(const string& n){
	name = n;
	flighthours = 0;
}

Part::~Part(){}

string Part::getName(){
	return name;
}

void Part::addFlightHours(int n){
	flighthours += n;
}

void Part::install(Date& d){
	installationDate = d;
}

void Part::print(){
	cout << name << " has flightHours: " << flighthours << endl;
}

bool Part::inspection(Date& d){
	//cout << "Calling Part::inspection" << endl;
	return false;
}

FH_Part::FH_Part(): Part(){
	fh_inspect = 0;
}

FH_Part::FH_Part(const string& name, int num): Part(name){
	fh_inspect = num;
}

FH_Part::~FH_Part(){}

bool FH_Part::inspection(Date& d){
	//cout << "Doing FH_INSPECTION" << endl;
	//cout << "Flighthours: " << flighthours << endl;
	//cout << "compared to: "<< fh_inspect<< endl;
	if (flighthours >= fh_inspect){
		//cout << "TRUE: should print part" << endl;
		return true;
	} else {
		return false;
	}
}

IT_Part::IT_Part(): Part(){
	it_inspect = 0;
}

IT_Part::IT_Part(const string& name, int num): Part(name){
	it_inspect = num;
}

IT_Part::~IT_Part(){}

bool IT_Part::inspection(Date& inspectDate){
	//cout << "Doing IT_PART INSPECTION" << endl;
	if ((inspectDate.toDays() - installationDate.toDays()) >= it_inspect){
		return true;
	} else {
		return false;
	}
}

FHIT_Part::FHIT_Part(): FH_Part(), IT_Part(), Part(){}

FHIT_Part::FHIT_Part(const string& name, int num_fh, int num_it):FH_Part(name, num_fh), IT_Part(name, num_it), Part(name){}

FHIT_Part::~FHIT_Part(){}

bool FHIT_Part::inspection(Date& d){
	//cout << "Doing FHIT INSPECTION" << endl;
	if (FH_Part::inspection(d) || IT_Part::inspection(d)){
		return true;
	} else {
		return false;
	}
}
