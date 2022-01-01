#include "IT_Part.h"

IT_Part::IT_Part(): Part(){
	it_inspect = 0;
}

IT_Part::IT_Part(const string& name, int num): Part(name){
	it_inspect = num;
}

IT_Part::~IT_Part(){}

bool IT_Part::inspection(Date& inspectDate){
	if ((inspectDate.toDays() - installationDate.toDays()) >= it_inspect){
		return true;
	} else {
		return false;
	}
}
