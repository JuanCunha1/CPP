#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

private:
    int _value;
};

#endif // DOG_HPP
