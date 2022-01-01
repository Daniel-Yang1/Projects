
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"


using namespace std;

class Store {
		
	public:
		//constructor
		Store();
		Store(const string& n);
		
		//destructor
		~Store();

		//other
		//findAvailableSLoc(StoreLocation**) finds the first Store that is available
		//meaning it has no product associated with it and points StoreLocation** to it
		void findAvailableSLoc(StoreLocation**);

		//similar function to findAvailableSLoc(StoreLocation**)
		void findAvailableWHLoc(WHLocation**);

		void printStoreStock();
		void printWareHouseStock();
		void printProducts();

		//these are done for you
		//findProduct searches the products List for a particular product specified by name
		//and points the Product** to it if it exists
		void findProduct(const string&, Product**);

		//receiveProduct checks if the Product exists already and if there is room at a Store for a
		//new product. If both of these conditions are met then a new Product is created and added
		//to the list of Products and associated with the free Store.
		void receiveProduct(const string&, int quantity);

		//fillOrder checks if the product exists in the list of products. If it does then 
		//it attempts to fill the order by calling prod->fillOrder.
		void fillOrder(const string&, int &quantity);
		void print();
	
	private:
		string name;
		StoreLocation storeArray[SLOCS];
		WHLocation whArray[WHLOCS];
		List* products;
	
};
#endif
