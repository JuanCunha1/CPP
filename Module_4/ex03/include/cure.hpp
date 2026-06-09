#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;
class Cure : public AMateria {
public:
    // Orthodox Canonical Form
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif // CURE_HPP
