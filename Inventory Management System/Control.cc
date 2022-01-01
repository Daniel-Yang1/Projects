
#include "Control.h"
#include "Queue.h"
#include "defs.h"
#include "StoreLocation.h"
#include "Store.h"
#include "Product.h"

const string Control::PRODUCTS[10] = {"Chocolate", "Beans", "Eggs", "Milk", "Winter Jackets", "Xbox", "Playstation", "Rakes", "AOL cd", "Bikes"};

 const int Control::QUANTITIES[10]= {100,200,300,150,350,300,200,200,150,100};

void Control::launch(){

    store = new Store("My Store");

    cout<<"initializing..."<<endl;

    initStore(store);
    
    cout<<"initialized!"<<endl;
    int choice = 5;

    while (choice!=0){
        view.showMenu(choice);
        switch(choice){
            case 1: receiveProduct(); break;
            case 2: fillOrder(); break;
            case 3: store->printStoreStock(); break;
            case 4: store->printWareHouseStock(); break;
            case 5: store->printProducts(); break;
        }
    }
    delete store;
}

void Control::receiveProduct(){
    string product;
    int quantity =0;
    view.getProduct(product);
    view.getQuantity(quantity);
    store->receiveProduct(product, quantity);
}

void Control::fillOrder(){
    string product;
    int quantity =0;
    view.getProduct(product);
    view.getQuantity(quantity);
    store->fillOrder(product, quantity);
    if (quantity > 0){
        cout<<"Short "<<quantity <<" "<<product<<"."<<endl;
    }
}

void Control::initStore(Store* store){
    for (int i = 0; i < 10; ++i){
        cout<<"receiving..."<<endl;
        store->receiveProduct(PRODUCTS[i],QUANTITIES[i]);
    }
}


void Control::locationTest(){
    string candy = "Candy";
	string junk = "Junk";
    StoreLocation loc1, loc2;
	Product* product = new Product(candy,&loc1);
	
	product->print();

	Product p(junk, &loc2);

	p.print();
	StoreLocation location;
	
	cout << "Unstocked location:"<<endl<<endl;
	
	location.print();

	int q = 10;
	

	location.add(product->getName(), q);
	cout<<"q: "<<location.getQuantity()<<endl;
	location.print();
	
	location.remove(q);
	location.print();
	q = 5;
	location.add(product->getName(), q);
	location.print();
	cout<<"q: "<<location.getQuantity()<<endl;

	q = 5;

	WHLocation loc;

	loc.print();
	loc.add(p.getName(), q);
	loc.print();
}

void Control::queueTest(){
    WHLocation back[5];
    Queue* q = new Queue();
    if(q->isEmpty()){
        cout<<"Queue is empty!"<<endl;
    }else{
        cerr<<red<<"Error: Queue not empty!"<<def<<endl;
    }

    cout<<"Adding 5 locations to q"<<endl;
    for (int i = 0; i < 5; ++i){
        q->addLast(&back[i]);
    }

    q->print();

    WHLocation* whloc;

    cout<<"Printing first item"<<endl;

    q->peekFirst(&whloc);
    whloc->print();

    cout<<"Deleting all but one.."<<endl;
    for (int i = 0; i < 4; ++i){
        q->popFirst(&whloc);
    }

    cout<<"Printing queue..."<<endl;

    q->print();

    cout<<"Printing first item"<<endl;

    q->peekFirst(&whloc);
    whloc->print();

    cout<<"Adding 4 locations to q"<<endl;
    for (int i = 0; i < 4; ++i){
        q->addLast(&back[i]);
    }

    cout<<"Printing queue..."<<endl;

    q->print();

    cout<<"Printing first item"<<endl;

    q->peekFirst(&whloc);
    whloc->print();

    cout<<"Deleting everything.."<<endl;

    for (int i = 0; i < 5; ++i){
        q->popFirst(&whloc);
    }

    cout<<"Printing empty queue..."<<endl;

    q->print();

    cout<<"Getting first item"<<endl;

    q->peekFirst(&whloc);
    if(whloc == NULL){
        cout<<"location is NULL"<<endl;
    }else{
        cout<<red<<"Possible error: empty queue did not return NULL"<<def<<endl;
    }

    cout<<"Adding in reverse order"<<endl;

    for (int i = 4; i >=0 ; --i){
        q->addLast(&back[i]);
    }

    cout<<"Printing reverse queue..."<<endl;

    q->print();

    cout<<"Printing first item"<<endl;

    q->peekFirst(&whloc);
    whloc->print();

    delete q;
}

