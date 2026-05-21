#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

class Cure {
public:
    // Orthodox Canonical Form
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

private:
    int _value;
};

#endif // CURE_HPP
