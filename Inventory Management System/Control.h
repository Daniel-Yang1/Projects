
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "View.h"

class Store;

using namespace std;

class Control {
		
	public:
		//launch() calls initStore and lets user decide what test to run
		void launch();


	private:
		Store* store;
		View view;
		//initStore takes in a Store pointer and initializes default values
		void initStore(Store*);

		//receiveProduct() calls store->receiveProduct(Product, Quantity) which adds a new Product
		//and associated Quantity to the Store
		void receiveProduct();
		
		//fillOrder() calls store->fillOrder(Product, Quantity) which attemps to reduce
		//the amount of Product stored by quantity Quantity. Prints remainder to screen
		//if unable to fill order completely
		void fillOrder();
		
		//locationTest() tests functionality of StoreLocation class and WHLocation classes
		//by adding a Product to each and calling the StoreLocation print and the WHLocation print
		//to see if the product has been added properly
		void locationTest();

		//queueTest() runs basic tests on the Queue class e.g. addLast(), popFirst(), peekFirst(), etc.
		void queueTest();

		static const string PRODUCTS[10];
		static const int QUANTITIES[10];
		
		
		
	
};
#endif