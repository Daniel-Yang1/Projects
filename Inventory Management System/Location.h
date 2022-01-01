#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string> 
#include "defs.h"

using namespace std;

class Location{
	
	public: 
		Location();
		Location(char,const int);
		
		bool isEmpty();

		//isAvailable() checks if Location is available by seeing if it already has a producted
		//assigned to it
		bool isAvailable();
		void print();
		
		//getters and setters
		string getId();
		string getProduct();
		void setProduct(const string&);
		void setNone();
		void setQuantity(int);
		int getQuantity();
		
		//virtual functions to be implemented by StoreLocation and WHLocation classes
		virtual int getCapacity();
		virtual bool add(const string&, int);
		virtual bool remove(int);

	private:
		string id;
		string product;
		int quantity;
		const static string NONE;

};

#endif
