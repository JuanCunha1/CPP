#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
private:
	std::string _type;

public:
	
	explicit Weapon(const std::string &type);
	
	std::string getType(void) const;
	
	void setType(const std::string &type);
};

#endif