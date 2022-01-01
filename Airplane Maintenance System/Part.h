#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Part {
	friend ostream& operator<<(ostream&, Part*);
	public:
		Part();
		Part(const string& n);
		virtual ~Part();
		
		string getName();
		
		//addFlightHours increases the flighthours member by int amount
		void addFlightHours(int);
		
		//install sets the installationDate member
		void install(Date&);
		
		void print();

		//inspection is implemented by the subclasses FH_Part, IT_Part and FHIT_Part
		virtual bool inspection(Date&);
		
		
	
	
	protected:
		string name;
		Date installationDate;
		int flighthours;
		




};

class FH_Part: virtual public Part{
	public:
		FH_Part();
		FH_Part(const string&, int);
		
		~FH_Part();

		//inspection checks whether the number of flighthours has exceeded fh_inspect
		virtual bool inspection(Date&);
	private:
		int fh_inspect;
};

class IT_Part: virtual public Part{
	public:
		IT_Part();
		IT_Part(const string&, int);
		
		~IT_Part();

		//inspection checks whether or not the time elapsed since the part was installed is
		//greater than it_inspect
		virtual bool inspection(Date&);
	private:
		int it_inspect;
};

class FHIT_Part: public FH_Part, public IT_Part{
	public:
		FHIT_Part();
		FHIT_Part(const string&, int, int);
		
		~FHIT_Part();

		//inspection calls FH_Part::inspection and IT_Part::inspection and returns true
		//if either of those functions return true
		virtual bool inspection(Date&);
	private:
};



#endif
