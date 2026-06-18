#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>
#include <exception>
#include <ctime>

class PmergeMe {
	private:
		std::deque<int> _deque;
		std::vector<int> _vector;
		int checkInput();
		PmergeMe(void);
	public:
		// Orthodox Canonical Form
		
		PmergeMe(int size, std::string *input);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#endif // PMERGEME_HPP
