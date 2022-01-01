#include "FHIT_Part.h"

FHIT_Part::FHIT_Part(): FH_Part(), IT_Part(), Part(){}

FHIT_Part::FHIT_Part(const string& name, int num_fh, int num_it):FH_Part(name, num_fh), IT_Part(name, num_it), Part(name){}

FHIT_Part::~FHIT_Part(){}

bool FHIT_Part::inspection(Date& d){
	if (FH_Part::inspection(d) || IT_Part::inspection(d)){
		return true;
	} else {
		return false;
	}
}
