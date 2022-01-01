
#include "Product.h"

Product::Product(const string& n, StoreLocation* sloc){
	name = n;
	storeLocation = sloc;
	whLocations = new Queue();
}

Product::~Product(){
	delete whLocations;
}

//getters
const string& Product::getName(){
	return name;
}

StoreLocation* Product::getStoreLocation(){
	return storeLocation;
}

void Product::setStoreLocation(StoreLocation* sloc){
	storeLocation = sloc;
}

void Product::addWHLocation(WHLocation* whloc){
	whLocations->addLast(whloc);
}

/* We take as much as we can from the storeLocation.
   The input-output parameter quantity returns 
   the amount left to fill in the order
*/
void Product::getFromStoreLocation(int& quantity){
	if (quantity > storeLocation->getQuantity()){
		quantity -= storeLocation->getQuantity();
		storeLocation->remove(storeLocation->getQuantity());
	}else{
		storeLocation->remove(quantity);
		quantity = 0;
	}

}

/* We try to fill the order with whatever is in
   the warehouse locations.
   The input-output parameter "quantity" returns 
   the amount left to fill in the order
*/
void Product::getFromWHLocations(int& quantity){
	WHLocation* loc;
	while(quantity>0){
		//there are no more warehouse locations storing 
		//this product - so break
		if (whLocations->isEmpty())break;

		//otherwise get the first whlocation
		whLocations->peekFirst(&loc);

		//if we empty the location, remove from the queue
		if (quantity > loc->getQuantity()){
			quantity -= loc->getQuantity();
			loc->remove(loc->getQuantity());
			whLocations->popFirst(&loc);
		}else{
			// we are not emptying the location,
			// but we have finished filling the order
			loc->remove(quantity);
			quantity = 0;
		}
	}
}

void Product::fillOrder(int& quantity){
	while (quantity > 0 && !storeLocation->isEmpty()){
		if (quantity < storeLocation->getQuantity()){
			storeLocation->remove(quantity);
			quantity = 0;
		}else{
			quantity -= storeLocation->getQuantity();
			storeLocation->remove(storeLocation->getQuantity());
			stockStoreLocation();
		}
	}

}

void Product::stockStoreLocation(){
	int q = storeLocation->getFreeSpace();
	int toAdd = q;
	getFromWHLocations(q);
	toAdd -= q;
	storeLocation->add(name, toAdd);
}

void Product::print(){
	cout << "Product:   "<<name<<endl;
}
