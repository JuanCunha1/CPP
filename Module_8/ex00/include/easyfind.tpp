#include "easyfind.hpp"
template <typename T> void easyfind(T& container, int toBeFound) {
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), toBeFound);
	if (it == container.end()) {
		throw ValueNotFound();
	} else {
		std::cout << "Value " << toBeFound << " found at position: "
					<< std::distance(container.begin(), it) << std::endl;
	}
}

const char *ValueNotFound::what() const throw() {
	return "The value was not found in the container";
}