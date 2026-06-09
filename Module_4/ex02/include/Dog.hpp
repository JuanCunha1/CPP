#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal{
public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();
    void makeSound() const;

private:
	Brain *DogBrain;
};


#endif // DOG_HPP
