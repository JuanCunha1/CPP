#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

class Character {
public:
    // Orthodox Canonical Form
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

private:
    int _value;
};

#endif // CHARACTER_HPP
