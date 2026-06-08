#include "Serializer.hpp"

int main() {
	Data data;

    data.value = 42;

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original:  " << ptr << std::endl;
    std::cout << "Recovered: " << recovered << std::endl;
    std::cout << "Value:     " << recovered->value << std::endl;

    return 0;
}
