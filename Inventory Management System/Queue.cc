#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

Queue::Queue(){
	head = NULL;
	tail = NULL;
}


Queue::~Queue(){
	Node* currNode = head;
	Node* nextNode = NULL;
	while (currNode != NULL){
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

bool Queue::isEmpty(){
	if (head == NULL){
		return true;
	} else {
		return false;
	}
}

void Queue::peekFirst(WHLocation** loc){
	if (head!=NULL){
		*loc = head->data;
	} else {
		*loc = NULL;
	}
}

void Queue::popFirst(WHLocation** loc){
	Node* temp;
	if (head!= NULL){
		*loc = head->data;
		temp = head;
		head = head->next;
		delete temp;
	} else {
		*loc = NULL;
	}
}

void Queue::addLast(WHLocation* loc){
	Node* temp = new Node();
	
	temp->data = loc;
	temp->next = NULL;
	
	if (isEmpty()){
		head = temp;
		tail = temp;
	} else {
		tail->next = temp;
		tail = temp;
	}
}

void Queue::print(){
	Node* temp = head;
	while (temp!=NULL){
		temp->data->print();
		temp = temp->next;
	}
}
