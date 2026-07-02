#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>
#include <exception>
#include <ctime>
#include <cerrno>
#include <set>
#include <algorithm>

class PmergeMe {
	private:
		std::deque<int> _deque;
		std::vector<int> _vector;
		int checkInput(const std::vector<std::string> &input);
		void print();
		void sortVector();
		void sortDeque();
		void fordJohnson(std::vector<int>& data);
		PmergeMe(void);
	public:
		// Orthodox Canonical Form
		
		PmergeMe(int size, char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};
#endif // PMERGEME_HPP
