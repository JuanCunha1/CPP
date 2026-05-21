#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>

class IMateriaSource {
public:
    // Orthodox Canonical Form
    IMateriaSource();
    IMateriaSource(const IMateriaSource& other);
    IMateriaSource& operator=(const IMateriaSource& other);
    ~IMateriaSource();

private:
    int _value;
};

#endif // IMATERIASOURCE_HPP
