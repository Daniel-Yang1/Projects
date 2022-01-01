#include "Airline.h"

Airline::Airline(){}

Airline::Airline(const string& n){
	name = n;
}

Airline::~Airline(){
	for (int i = 0; i < parts.getSize(); i++){
		delete parts[i];
	}
	for (int i = 0; i < aircraft.getSize(); i++){
		delete aircraft[i];
	}
}
//getters
Aircraft* Airline::getAircraft(const string& reg){
	for (int i = 0; i < aircraft.getSize(); i++){
		if (aircraft[i]->getRegistration() == reg){
			return aircraft[i];	
		}
	}
}

Part* Airline::getPart (const string& p){
	for (int i = 0; i < parts.getSize(); i++){
		if (parts[i]->getName() == p){
			return parts[i];
		}
	}
}

void Airline::addAircraft(const string& type, const string& reg){
	Aircraft* temp = new Aircraft(type, reg);
	aircraft.add(temp);
}

void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
	Part* temp;
	
	if (fh_inspect == 0){
		temp = new IT_Part(part, it_inspect);
	} else if (it_inspect == 0){
		temp = new FH_Part(part, fh_inspect);
	} else {
		temp = new FHIT_Part(part, fh_inspect, it_inspect);
	}
	parts.add(temp);
}

void Airline::takeFlight(const string& reg, int hours){
	Aircraft* temp = getAircraft(reg);
	temp->takeFlight(hours);
}

void Airline::printAircraft(){
	cout <<aircraft << endl;
}

void Airline::printParts(){
	for (int i = 0; i < parts.getSize(); i++){
		parts[i]->print();
	}
}

void Airline::inspectionReport(const string& reg, Date& d){
	Array<Part*>* temp = new Array<Part*>();
	for (int i = 0; i < aircraft.getSize(); i++){
		if (aircraft[i]->getRegistration() == reg){
			aircraft[i]->inspectionReport(d, temp);
		}
	}
	cout << "Airplane registration is: " << reg << endl;
	//cout << temp[0] << endl;
	cout << "temp SIZE in AIRLINE:: is : " << temp->getSize() << endl;
	for (int i = 0 ; i < temp->getSize(); i++){
		(*temp)[i]->print();
	};
	delete temp;
}

bool Airline::install(const string& reg, const string& n, Date& d){
	for (int i = 0; i < aircraft.getSize(); i++){
		if (aircraft[i]->getRegistration() == reg){
			for (int j = 0; j < parts.getSize(); j++){
				if (parts[j]->getName() == n){
					aircraft[i]->install(parts[j], d);
					return true;
				}
			}
		}
	}
	return false;
}



