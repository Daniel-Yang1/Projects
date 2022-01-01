#include "List.h"

List::List(): head(NULL){}

List::~List(){
	Node* currNode = head;
	Node* nextNode = NULL;
	
	while (currNode!=NULL){
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}
}

void List::add(Product* p){
	Node* newNode = new Node;
	newNode->data = p;
	newNode->next = NULL;
	
	Node* currNode = head;
	Node* prevNode = NULL;
	
	while (currNode!=NULL){
		if (newNode->data->getName() < currNode->data->getName()){
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;		
	}
	if (prevNode == NULL){
		head = newNode;
		newNode->next = currNode;
	} else {
		prevNode->next = newNode;
		newNode->next = currNode;
	}	
}

void List::del(const string& name, Product** p){
	Node* currNode;
	Node* prevNode;
	
	currNode = head;
	prevNode = NULL;
	
	while (currNode!= NULL){
		if (currNode->data->getName() == name){
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}	
	if (currNode == NULL){
		*p = NULL;
		return;
	}
	
	if (prevNode == NULL){
		head = currNode->next;
	} else {
		prevNode->next = currNode->next;
	}
	*p = currNode->data;
	delete currNode;
}

bool List::isEmpty(){
	if (head == NULL){
		return true;
	} else {
		return false;
	}
}

void List::findProduct(const string& name, Product** prod){
	*prod = NULL;
	Node* currNode = head;
	
	while (currNode != NULL){
		if (currNode->data->getName() == name){
			*prod =  currNode->data;
			break;
		} else {
			currNode = currNode->next;
		}
	}
}


void List::print(){
	Node* currNode = head;
	while (currNode != NULL){
		currNode->data->print();
		currNode = currNode->next;
	}
}
