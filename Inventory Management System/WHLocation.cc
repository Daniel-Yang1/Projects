#include "WHLocation.h"

const char WHLocation::code = 'B';
int WHLocation::capacity = WHLOC_CAPACITY;
int WHLocation::nextId = 0;

WHLocation::WHLocation(): Location(code, nextId){
	nextId++;
}

int WHLocation::getCapacity(){
	return capacity;
}

bool WHLocation::add (const string& n, int amount){
	if (isAvailable() && (amount <= getCapacity())){
			setProduct(n);
			setQuantity(amount);
			return true;
	} else {
		return false;
	}
}

bool WHLocation::remove(int amount){
	if (getQuantity() < amount){
		return false;
	} else {
		setQuantity(getQuantity() - amount);
		if (getQuantity() == 0){
			setNone();
		}
		return true;
	}
}
