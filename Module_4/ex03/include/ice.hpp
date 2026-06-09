#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class AMateria;

class Ice : public AMateria {
public:
    // Orthodox Canonical Form
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    AMateria *clone() const;
    void use(ICharacter &target);
private:
};

#endif // ICE_HPP
