#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include <list>

#define SLOTS 4

class ICharacter;
class AMateria;

class Character : public ICharacter{
public:
    // Orthodox Canonical Form
    Character();
    Character(std::string const &name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
	std::string _name;
	AMateria *_inventory[SLOTS];
	std::list<AMateria *> _unequipedMaterias;
};

#endif // CHARACTER_HPP
