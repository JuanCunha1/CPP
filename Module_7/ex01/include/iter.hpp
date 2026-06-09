#ifndef ITER_HPP
#define ITER_HPP

#include <functional>

template <typename T>
void iter(T *array, const size_t length, void (*func)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif // ITER_HPP