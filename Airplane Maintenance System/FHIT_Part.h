#ifndef FHIT_PART_H
#define FHIT_PART_H

#include <iostream>
#include <string>
#include "Part.h"
#include "FH_Part.h"
#include "IT_Part.h"

using namespace std;

class FHIT_Part: public FH_Part, public IT_Part{
	public:
		FHIT_Part();
		FHIT_Part(const string&, int, int);
		
		~FHIT_Part();

		//inspection calls both FH_Part::inspection() and IT_Part::inspection
		//true if either of those are true
		virtual bool inspection(Date&);
	private:
};


#endif
