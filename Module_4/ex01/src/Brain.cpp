#include "Brain.hpp"

// Construtor padrão
Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;\
	RandomIdeas();
}

// Construtor de cópia
Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

// Operador de atribuição
Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

// Destrutor
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::RandomIdeas() {
  const std::string random_ideas[] = {
	  "Where am I?",
	  "Let's play!",
	  "I wanna run",
	  "I want a friend!",
	  "Dreaming of chasing squirrels",
	  "Wondering when my human will be back",
	  "Planning my next nap",
	  "Contemplating the meaning of life (and treats)",
	  "Pondering the mysteries of the vacuum cleaner",
	  "Plotting to steal a sock",
	  "Fantasizing about a world where treats fall from the sky",
	  "Calculating the perfect time to wake up my human",
	  "Daydreaming about chasing my tail",
	  "Considering a career as a professional beggar",
	  "Planning a midnight zoomies session",
	  "Wondering if I'm a good boy/girl",
	  "Fantasizing about the forbidden pleasures of the garbage can",
	  "Contemplating the existential crisis of the red dot",
	  "Plotting the ultimate escape from the bath"};
  for (int i = 0; i < IDEAS; i++)
	this->ideas[i] = random_ideas[rand() % 6];
}
