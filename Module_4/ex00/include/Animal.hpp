#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    // Orthodox Canonical Form
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    ~Animal();

protected:
	std::string type;
};

#endif // ANIMAL_HPP
