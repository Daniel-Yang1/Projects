
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T> 
class Array {
	template <class U>
	friend ostream& operator<<(ostream&, Array<U>&);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		T& operator[](int index);
		void add(T);
		//int get(int index);
		int getSize();
		bool isFull();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
ostream& operator<<(ostream& out, Array<T>& arr){
	for (int i = 0; i < arr.size; i++){
		out << arr.elements[i];
	}
	return out;
}


template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	//delete [] elements;
}

template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize(){
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

/*int Array::get(int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}*/

template <class T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= size){
		cout << "Invalid index" << endl;
		exit(-1);
	}
	return elements[index];
}
#endif
