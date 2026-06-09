#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

class IMateriaSource {
public:
    // Orthodox Canonical Form
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif // IMATERIASOURCE_HPP
