#include "StoreLocation.h"

const char StoreLocation::code = 'A';
int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 0;

StoreLocation::StoreLocation(): Location(code, nextId){
	nextId++;
}

StoreLocation::~StoreLocation(){

}

void StoreLocation::setProduct(const string& p){
	Location::setProduct(p);
}

int StoreLocation::getFreeSpace(){
	return capacity - getQuantity();
}

int StoreLocation::getCapacity(){
	return capacity;
}

bool StoreLocation::add(const string& n, int amount){
	if (isAvailable()){
		if (getFreeSpace() >= amount){
			setProduct(n);
			setQuantity(amount);
			return true;
		} else {
			return false;
		}
	} else {
		if (getProduct().compare(n) == 0){
			if (getFreeSpace() >= (amount)){
				setQuantity(amount + getQuantity());
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
}

bool StoreLocation::remove(int amount){
	if (getQuantity() < amount){
		return false;
	} else {
		setQuantity(getQuantity() - amount);
		return true;
	}
}

void StoreLocation::print(){
	Location::print();
}

