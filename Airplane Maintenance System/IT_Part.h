#ifndef IT_PART_H
#define IT_PART_H

#include <iostream>
#include <string>
#include "Part.h"

using namespace std;

class IT_Part: virtual public Part{
	public:
		IT_Part();
		IT_Part(const string&, int);
		
		~IT_Part();

		//inspection checks if the number of days elapsed since the part's installation date is greater than
		//it_inspect
		virtual bool inspection(Date&);
	private:
		int it_inspect;
};


#endif
