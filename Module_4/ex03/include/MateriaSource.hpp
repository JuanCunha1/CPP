#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

class MateriaSource {
public:
    // Orthodox Canonical Form
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

};

#endif // MATERIASOURCE_HPP
