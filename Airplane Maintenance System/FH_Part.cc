#include "FH_Part.h"

FH_Part::FH_Part(): Part(){
	fh_inspect = 0;
}

FH_Part::FH_Part(const string& name, int num): Part(name){
	fh_inspect = num;
}

FH_Part::~FH_Part(){}

bool FH_Part::inspection(Date& d){
	if (flighthours >= fh_inspect){
		return true;
	} else {
		return false;
	}
}
