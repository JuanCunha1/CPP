#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    FragTrap();
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    int getValue() const;
    void setValue(int value);
    void highFivesGuys(void);
   


private:
    
};

#endif // FRAGTRAP_HPP
