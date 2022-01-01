#include "Location.h"
const string Location::NONE = "Empty";

Location::Location(){
	id = "tempID";
	product = NONE;
	quantity = 0;
}

Location::Location(char c, const int n){
	string temp(1, c);
	temp = temp + to_string(n);
	id = temp;
	product = NONE;
	quantity = 0;
}

bool Location::isEmpty(){
	if (quantity == 0){
		return true;
	} else {
		return false;
	}
}

bool Location::isAvailable(){
	if (product.compare(NONE) == 0){
		return true;
	} else {
		return false;
	}
}

void Location::print(){
	//cout << "Calling Location::print()" << endl;
	cout << "Id is: " << id << endl;
	cout << "Product is: " << product << endl;
	cout << "Quantity is: " << quantity << endl;
}

string Location::getId(){
	return id;
}

string Location::getProduct(){
	return product;
}

void Location::setProduct(const string& p){
	product = p;
}

void Location::setNone(){
	product = NONE;
}

void Location::setQuantity(int n){
	quantity = n;
}

int Location::getCapacity(){
	cout << "Calling Location::getCapacity" << endl;
	return 1;
}

int Location::getQuantity(){
	return quantity;
}

bool Location::add(const string& s, int n){
	cout << "Calling Location::add" << endl;
	return false;
}

bool Location::remove(int n){
	cout << "Calling Location::remove" << endl;
	return false;
}


