#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	// Orthodox Canonical Form
	explicit Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
protected:
	std::string type;
};

#endif // ANIMAL_HPP
