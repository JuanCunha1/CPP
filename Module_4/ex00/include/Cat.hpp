#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
public:
    // Orthodox Canonical Form
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

private:
    int _value;
};

#endif // CAT_HPP
