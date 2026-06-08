#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	std::srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		Base *derivedClass = generate();
		identify(derivedClass);
		identify(*derivedClass);
		delete derivedClass;
	}
	return 0;
}
