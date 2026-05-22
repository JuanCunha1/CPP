#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

# define IDEAS 100

class Brain {
public:
    // Orthodox Canonical Form
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    void	RandomIdeas(void);
private:
    std::string ideas[IDEAS];
};

#endif // BRAIN_HPP
