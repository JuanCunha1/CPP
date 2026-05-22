#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() {
    Dog dog;
    Cat cat;

    std::cout << dog.getType() << ": ";
    dog.makeSound();

    std::cout << cat.getType() << ": ";
    cat.makeSound();

    //Animal animal; // ❌ ERROR: cannot instantiate abstract class
	return 0;
}
