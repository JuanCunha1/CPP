#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria {
protected:
    // Orthodox Canonical Form
    AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    ~AMateria();

public:
    AMateria(std::string const & type);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP
