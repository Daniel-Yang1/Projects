#ifndef STORE_LOCATION_H
#define STORE_LOCATION_H

#include <iostream>
#include <string>
#include <cstring>
#include "defs.h"
#include "Location.h"

using namespace std;

class StoreLocation : public Location{

	public:
		StoreLocation();
		~StoreLocation();

		//getter and setter
		void setProduct (const string&);
		int getFreeSpace();
		
		//getCapacity returns the capacity of the store
		virtual int getCapacity();

		//add attempts to add a certain quantity of a product to the store. Stores can only hold 1 product
		//so attempts to add a new product to a store that already holds a different product will 
		//do nothing except return false
		//Attempting to add to a store that has no free space will also result in nothing except return false
		virtual bool add(const string&, int);

		//remove(int) removes int number of product from the store. 
		virtual bool remove(int);
	
		void print();
	private:
		const static char code;
		static int capacity;
		static int nextId;	
};

#endif
