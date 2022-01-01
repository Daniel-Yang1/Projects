#ifndef FH_PART_H
#define FH_PART_H

#include <iostream>
#include <string>
#include "Part.h"

using namespace std;

class FH_Part: virtual public Part{
	public:
		FH_Part();
		FH_Part(const string&, int);
		
		~FH_Part();

		//if the current number of flightHours is greater than fh_inspect then true
		virtual bool inspection(Date&);
	private:
		int fh_inspect;
};


#endif
