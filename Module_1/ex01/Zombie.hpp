#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define HORDE_NUMBER 5

class Zombie {

private:
	std::string name;

public:
	void	announce(void);

	void	SetName(const std::string InputName);

	~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
