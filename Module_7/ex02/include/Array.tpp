#include "Array.hpp"

template <class T> Array<T>::Array() : _size(0) {
	std::cout << "[Array] Default Constructor called!" << std::endl;
	this->_array = new T[0];
};

template <class T> Array<T>::Array(unsigned int n) : _size(n) {
	std::cout << "[Array] Constructor called!" << std::endl;
	this->_array = new T[n];
};

template <class T> Array<T>::Array(const Array &other) {
	this->_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
	this->_size = other._size;
}

template <class T> Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other)
		return *this;
	delete[] this->_array;
	this->_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
	this->_size = other._size;
	return *this;
}

template <class T> Array<T>::~Array() {
	delete[] this->_array;
	std::cout << "[Array] Destructor called!" << std::endl;
};

template <class T> unsigned int Array<T>::size() const {
	return this->_size;
};

template <class T> T &Array<T>::operator[](unsigned int i) {
	if (i >= this->size())
		throw OutOfRange();
	return this->_array[i];
};

template <class T> const char *Array<T>::OutOfRange::what() const throw() {
	return "Index is out of range.";
}