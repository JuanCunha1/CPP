#include "Serializer.hpp"

// Constructor padrão
Serializer::Serializer() {
	//std::cout << "Serializer default constructor called" << std::endl;
}

// Constructor de cópia
Serializer::Serializer(const Serializer& other) {
	//std::cout << "Serializer copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
Serializer& Serializer::operator=(const Serializer& other) {
	//std::cout << "Serializer assignment operator called" << std::endl;
	if (this != &other) {
		return *this;
	}
	return *this;
}

// Destructor
Serializer::~Serializer() {
	//std::cout << "Serializer destructor called" << std::endl;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
