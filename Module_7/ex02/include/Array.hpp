#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstdlib>
#include <ctime>
#include <iostream>

template <class T> class Array {
	private:
		T *array_;
		unsigned int size_;
	public:
	// Orthodox Canonical Form
		Array(void);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		Array(unsigned int n);
		unsigned int size() const;
		T& operator[](unsigned int i);
		class OutOfRange : public std::exception {
			/** @brief Throws an exception indicating that the index is out of range. */
			const char *what() const throw();
  		};
};

#include "Array.tpp"

#endif // ARRAY_HPP
