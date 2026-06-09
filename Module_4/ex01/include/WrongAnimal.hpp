#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	// Orthodox Canonical Form
	explicit WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
	virtual void makeSound() const; // Pure virtual function
	std::string getType() const;
protected:
	std::string _type;
};

#endif // WRONGANIMAL_HPP
