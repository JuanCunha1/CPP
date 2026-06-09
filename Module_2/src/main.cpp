#include "test.hpp"

int main() {
    std::cout << "--- Test OCF ---" << std::endl;

    Test a;
    Test b(a);
    Test c;

    c = b;

    return 0;
}
