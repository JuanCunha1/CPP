#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	std::cout << "==== Wrong classes tests ====\n";

	// Additional tests with WrongCat
	const WrongAnimal *metaa = new WrongAnimal();
	const WrongAnimal *jj = new WrongCat();
	const WrongAnimal *ii = new WrongCat();
	std::cout << jj->getType() << " " << std::endl;
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound(); // will output the cat sound!
	jj->makeSound();
	metaa->makeSound();

	delete metaa;
	delete jj;
	delete ii;
	return 0;
}
