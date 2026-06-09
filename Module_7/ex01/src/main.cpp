
#include <iostream>
#include "iter.hpp"
#include <string>

void print(const int &value) {
	std::cout << value << std::endl;
}
void print(const std::string &value) {
	std::cout << value << std::endl;
}
void print(const float &value) {
	std::cout << value << std::endl;
}
int main() {
	{
		std::cout << "------------------SUBJECT TESTS------------------" << std::endl;
		int a[] = {1, 2, 3, 4, 5};
		std::string b[] = {"Hello", "World", "42", "School"};
		
		::iter(a, 5, print);
		::iter(b, 4, print);
	}
	{
		std::cout << "------------------TEST WITH FLOATS------------------" << std::endl;
		float c[] = {3.14f, 2.71f, 1.41f, 0.577f};
		::iter(c, 4, print);
	}
	{
		std::cout << "------------------TEST WITH STRINGS------------------" << std::endl;
		std::string d[] = {"C++", "Templates", "Iterators"};
		::iter(d, 3, print);
	}
	
	return 0;
}