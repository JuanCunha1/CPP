#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria {
protected:
	/* The Type of the AMateria */
	std::string _type;

public:
	// Orthodox Canonical Form
	AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP
