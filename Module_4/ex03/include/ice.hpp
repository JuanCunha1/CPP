#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

class Ice {
public:
    // Orthodox Canonical Form
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

private:
    int _value;
};

#endif // ICE_HPP
