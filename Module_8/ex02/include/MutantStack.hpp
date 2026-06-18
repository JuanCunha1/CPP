#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
public:
	// Orthodox Canonical Form
	MutantStack(void);
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	typedef typename C::iterator iterator;

	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"
#endif // MUTANTSTACK_HPP
