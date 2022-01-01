#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"
using namespace std;

//List is an implementation of a Linked List
class List{
	
	class Node {
		public:
			Product* data;
			Node* next;
	};

	public:
		List();
		~List();
		void add(Product*);

		//finds and deletes product with name "name" from the List. The deleted item is passed to Product**
		void del(const string& name, Product**);
		//new member functions
		bool isEmpty();

		//Finds product with name "name" and points prod to that product.
		void findProduct(const string& name, Product** prod);
		
		void print();
		
	private:
		Node* head;




};
#endif
