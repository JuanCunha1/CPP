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
#include <sstream>
#include <climits>

class PmergeMe {
	private:
		struct Pair
		{
			int small;
			int large;
		};
		
		std::deque<int> _deque;
		std::vector<int> _vector;

		// General helpers
		int parseInput(const std::vector<std::string>& input);
		void print();

		// Vector Ford-Johnson
		static std::vector<int> extractLargeElements(const std::vector<Pair>& pairs);
		static std::vector<size_t> generateJacobsthalOrder(size_t size);
		static std::vector<Pair> reorderPairs(std::vector<Pair>& pairs, const std::vector<int>& largeElements);
		static std::vector<int> buildMainChain(const std::vector<Pair>& orderedPairs);
		static void insertPending(std::vector<int>& mainChain, const std::vector<Pair>& pair);
		static void fordJohnson(std::vector<int>& data);
		static std::vector<Pair> generatePairs(const std::vector<int>& data);

		// Deque Ford-Johnson
		static std::deque<int> extractLargeElements(const std::deque<Pair>& pairs);
		static std::deque<size_t> generateDequeJacobsthalOrder(size_t size);
		static std::deque<Pair> reorderPairs(std::deque<Pair>& pairs, const std::deque<int>& largeElements);
		static std::deque<int> buildMainChain(const std::deque<Pair>& orderedPairs);
		static void insertPending(std::deque<int>& mainChain, const std::deque<Pair>& pair);
		static void fordJohnson(std::deque<int>& data);
		static std::deque<Pair> generatePairs(const std::deque<int>& data);
		
		PmergeMe(void);

	public:
		PmergeMe(int size, char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};
#endif // PMERGEME_HPP
