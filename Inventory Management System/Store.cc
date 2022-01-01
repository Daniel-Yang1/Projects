
#include "Store.h"

Store::Store(){
	name = "tempStore";
	/*for (int i = 0; i < SLOCS; i++){
		storeArray[i] = new StoreLocation;
	}
	for (int i = 0; i < WHLOCS; i++){
		whArray[i] = new WHLocation;
	}
	*/
	products = new List();
}
Store::Store(const string& n){
	name = n;
	/*for (int i = 0; i < SLOCS; i++){
		storeArray[i] = new StoreLocation;
	}
	for (int i = 0; i < WHLOCS; i++){
		whArray[i] = new WHLocation;
	}*/
	products = new List();
}

Store::~Store(){
	/*for (int i = 0; i < SLOCS; i++){
		delete storeArray[i];
	}
	for (int i = 0; i < WHLOCS; i++){
		delete whArray[i];
	}*/
	delete products;
}

void Store::findAvailableSLoc(StoreLocation** sloc){
	for (int i = 0; i < SLOCS; i++){
		if (storeArray[i].isAvailable()){
			*sloc = &storeArray[i];
			break;
		}
	}
}

void Store::findAvailableWHLoc(WHLocation** wloc){
	for (int i = 0; i < WHLOCS; i++){
		if (whArray[i].isAvailable()){
			*wloc = &whArray[i];
		}
	}
}

void Store::findProduct(const string& n, Product** prod){
	products->findProduct(n, prod);
}


//print methods

void Store::printStoreStock(){
	for (int i = 0; i < SLOCS; i++){
		if (!storeArray[i].isAvailable()){
			storeArray[i].print();
		}
	}
}

void Store::printWareHouseStock(){
	for (int i = 0; i < WHLOCS; i++){
		if (!whArray[i].isAvailable()){
			whArray[i].print();
		}
	}
}

void Store::printProducts(){
	products->print();
}
void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        //cout << "CREATION OF SLOC OKAY" << endl;
        findAvailableSLoc(&sloc);
        //cout << "FIND AVAILABLESLOC OKAY" << endl;
        prod = new Product(pname, sloc);
        //cout << "CREATION OF NEW PROD OKAY" << endl;
        products->add(prod);
        //cout << "ADD PROD TO PRODUCTS OKAY" << endl;
        
    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print(){
    cout<<"Store: "<<name<<endl;
}
