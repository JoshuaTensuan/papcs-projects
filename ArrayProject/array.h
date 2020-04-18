// Joshua Tensuan
#include <math.h>
#include <iostream>
using namespace std;
#ifndef ARRAY_H_
#define ARRAY_H_

/*
array is the name of the array class
.get method takes in an int parameter and outputs the value in the array at that index
.set method takes in an int and template parameters and changes the value in the array at the int index to the template parameter
~array() is the destructor method
*/

// A template class is used so that an array can be made of any data type at discretion of user
template <typename T> class array {
public:
	array();
	array(int);
	T get(int);
	void set(int, T);
	virtual ~array(); // virtual destructor that allows destruction of array even when extended
	// declaration of public methods
private:
	// declaration of private fields
	T *arr;
    int size;
};

template <typename T> array<T>::~array() {
	free (arr);
	// destructor
}

template <typename T> array<T>::array() {
	// empty default constructor
}

template <typename T> array<T>::array(int s) {
	size = s;
    arr = (T*)malloc(sizeof(T) * s);
	// constructor that takes in an int s and allocates memory for the array based of the size s
}

template <typename T> T array<T>::get(int index) {
	return *(arr + index);
	// a get method that takes an index and outputs the value at that index
}

template <typename T> void array<T>::set(int index, T value) {
	*(arr + index) = value;
	// a set method that takes an index and templated value and changes the value in the array at the specified index to the templated value
}

#endif