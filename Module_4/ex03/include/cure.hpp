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
};

#endif // CURE_HPP
