#ifndef QUEUE_H
#define QUEUE_H
#include "WHLocation.h"
#include "Location.h"

class Queue{

	class Node {
		public:
			WHLocation* data;
			Node* next;
	};

	public:
		Queue();
		~Queue();
		bool isEmpty();
		//peekFirst(WHLocation** loc) returns a pointer to the first element
		//of the Queue 
		void peekFirst(WHLocation** loc);

		//popFirst(WHLocation** loc) returns a pointer to the first element of the 
		//Queue and also removes that item from the front of the Queue
		void popFirst(WHLocation** loc);

		void addLast(WHLocation* loc);
		
		void print();
		
	private:
		Node* head;
		Node* tail;
};


#endif
