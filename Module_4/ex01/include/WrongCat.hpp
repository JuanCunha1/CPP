#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

class WrongCat {
public:
    // Orthodox Canonical Form
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

private:
    int _value;
};

#endif // WRONGCAT_HPP
