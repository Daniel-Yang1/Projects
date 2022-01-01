#ifndef WHLOCATION_H
#define WHLOCATION_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Location.h"

using namespace std;

class WHLocation : public Location{

	public:
		WHLocation();
		
		//getter
		virtual int getCapacity();

		//add attempts to add int quantity of product const string& to the warehouseLocation
		//if the warehouse is full or is not available then then the function will do nothing
		//except return false
		virtual bool add(const string&, int);

		//remove(int) attempts to remove an int quantity of product from the warehouseLocation
		//If we attempt to remove more than what is available at the warehouseLocation then
		//the function will simply return faslse
		virtual bool remove(int);

	private:
		const static char code;
		static int capacity;
		static int nextId;

};

#endif
