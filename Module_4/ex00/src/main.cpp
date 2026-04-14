#include "Animal.hpp"

int main() {
    std::cout << "--- Test OCF ---" << std::endl;

    Animal a;
    Animal b(a);
    Animal c;

    c = b;

    return 0;
}
