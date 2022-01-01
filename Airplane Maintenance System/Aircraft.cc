#include "Aircraft.h"

ostream& operator<<(ostream& out, Array<Part*>& ps){
	for (int i = 0; i < ps.getSize(); i++){
		out << ps[i] << endl;
	}
	return out;
}

Aircraft::Aircraft(){
}

Aircraft::Aircraft(const string& t, const string& reg){
	type = t;
	registration = reg;
	int flighthours = 0;
}

Aircraft::~Aircraft(){}

string Aircraft::getRegistration(){
	return registration;
}

void Aircraft::install(Part* p, Date& d){
	p->install(d);
	parts.add(p);
}

void Aircraft::takeFlight(int hours){
	flighthours += hours;
	for (int i = 0; i < parts.getSize(); i++){
		parts[i]->addFlightHours(hours);
	}
}

void Aircraft::inspectionReport(Date& d, Array<Part*>* output){
	for (int i = 0; i < parts.getSize(); i++){
		if (parts[i]->inspection(d)){
			output->add(parts[i]);
			//cout << "temp size is: " << output.getSize() << endl;
		}
	}
}


