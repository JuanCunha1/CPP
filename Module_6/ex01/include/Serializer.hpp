#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	int	value;
};

class Serializer {

	private:
		// Orthodox Canonical Form
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		
	public:
		~Serializer();
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
