#include "PmergeMe.hpp"

// Constructor padrão
PmergeMe::PmergeMe() {
	//std::cout << "PmergeMe default constructor called" << std::endl;
}

// Constructor de cópia
PmergeMe::PmergeMe(const PmergeMe& other) {
	//std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	//std::cout << "PmergeMe assignment operator called" << std::endl;
	if (this != &other) {
		
	}
	return *this;
}

// Destructor
PmergeMe::~PmergeMe() {
	//std::cout << "PmergeMe destructor called" << std::endl;
}


PmergeMe::PmergeMe(int size, char **argv) {
	std::vector<std::string> input(argv + 1, argv + size);
	if(parseInput(input))
		throw std::runtime_error("Error");
	print();
}

int PmergeMe::parseInput(const std::vector<std::string>& input)
{
	std::set<int> seen;
	std::vector<int> tempVector;
	std::deque<int> tempDeque;

	for (size_t i = 0; i < input.size(); ++i)
	{
		if (input[i].empty())
			return (1);

		if (input[i].find_first_not_of("0123456789")
			!= std::string::npos)
			return (1);

		std::stringstream stream(input[i]);
		long value;

		stream >> value;

		if (stream.fail() || !stream.eof())
			return (1);

		if (value > INT_MAX)
			return (1);

		if (!seen.insert(static_cast<int>(value)).second)
			return (1);

		tempVector.push_back(static_cast<int>(value));
		tempDeque.push_back(static_cast<int>(value));
	}

	_vector = tempVector;
	_deque = tempDeque;

	return (0);
}

void PmergeMe::print() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;

	clock_t vectorStart = clock();
	fordJohnson(_vector);
	clock_t vectorEnd = clock();

	clock_t dequeStart = clock();
	fordJohnson(_deque);
	clock_t dequeEnd = clock();

		std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	double vectorTime =
		static_cast<double>(vectorEnd - vectorStart)
		/ CLOCKS_PER_SEC * 1000000.0;

	double dequeTime =
		static_cast<double>(dequeEnd - dequeStart)
		/ CLOCKS_PER_SEC * 1000000.0;

	std::cout
		<< "Time to process a range of "
		<< _vector.size()
		<< " elements with std::vector : "
		<< vectorTime
		<< " us"
		<< std::endl;

	std::cout
		<< "Time to process a range of "
		<< _deque.size()
		<< " elements with std::deque : "
		<< dequeTime
		<< " us"
		<< std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t size)
{
	std::vector<size_t> order;
	if (size <= 1)
		return order;
	size_t previousJacob = 1;
	size_t currentJacob = 3;
	size_t lastInserted = 1;
	while (lastInserted < size)
	{
		size_t upper = currentJacob;
		if (upper > size)
			upper = size;
		for (size_t i = upper; i > lastInserted; --i)
			order.push_back(i - 1);
		lastInserted = upper;
		size_t nextJacob =
			currentJacob + (2 * previousJacob);
		previousJacob = currentJacob;
		currentJacob = nextJacob;
	}
	return order;
}

std::vector<int> PmergeMe::extractLargeElements(const std::vector<Pair>& pairs)
{
	std::vector<int> largeElements;

	size_t size = pairs.size();
	for (size_t i = 0; i < size; ++i)
		largeElements.push_back(pairs[i].large);

	return largeElements;
}

std::vector<PmergeMe::Pair>
PmergeMe::generatePairs(const std::vector<int>& data)
{
	std::vector<Pair> pairs;

	size_t size = data.size();
	for (size_t i = 0; i + 1 < size; i += 2)
	{
		Pair pair;

		if (data[i] < data[i + 1])
		{
			pair.small = data[i];
			pair.large = data[i + 1];
		}
		else
		{
			pair.small = data[i + 1];
			pair.large = data[i];
		}

		pairs.push_back(pair);
	}

	return pairs;
}

std::vector<PmergeMe::Pair> PmergeMe::reorderPairs(std::vector<Pair>& pairs, const std::vector<int>& largeElements)
{
	std::vector<Pair> orderedPairs;

	size_t	elementSize = largeElements.size();
	size_t	pairsSize = pairs.size();

	for (size_t i = 0; i < elementSize; ++i)
	{
		for (size_t j = 0; j < pairsSize; ++j)
		{
			if (pairs[j].large == largeElements[i])
			{
				orderedPairs.push_back(pairs[j]);
				break;
			}
		}
	}

	return orderedPairs;
}

std::vector<int> PmergeMe::buildMainChain(const std::vector<Pair>& orderedPairs)
{
	std::vector<int> mainChain;

	if (orderedPairs.empty())
		return mainChain;

	mainChain.push_back(orderedPairs[0].small);

	size_t size = orderedPairs.size();
	for (size_t i = 0; i < size; ++i)
		mainChain.push_back(orderedPairs[i].large);

	return mainChain;
}

void PmergeMe::insertPending(
	std::vector<int>& mainChain,
	const std::vector<Pair>& pairs)
{
	size_t pairsSize = pairs.size();
	std::vector<size_t> insertionOrder =
		generateJacobsthalOrder(pairsSize);

	size_t size = insertionOrder.size();
	for (size_t i = 0; i < size; ++i)
	{
		size_t pairIndex = insertionOrder[i];

		if (pairIndex >= pairsSize)
			continue;

		int pendingValue = pairs[pairIndex].small;
		int pairedValue = pairs[pairIndex].large;

		std::vector<int>::iterator pairedPosition =
			std::find(
				mainChain.begin(),
				mainChain.end(),
				pairedValue
			);

		std::vector<int>::iterator insertPosition =
			std::lower_bound(
				mainChain.begin(),
				pairedPosition,
				pendingValue
			);

		mainChain.insert(insertPosition, pendingValue);
	}
}

void PmergeMe::fordJohnson(std::vector<int>& data)
{
	size_t size = data.size();
	if (size <= 1)
		return;

	bool hasStraggler = (size % 2 != 0);
	int straggler = hasStraggler ? data.back() : 0;

	std::vector<Pair> pairs = generatePairs(data);

	std::vector<int> largeElements = extractLargeElements(pairs);

	fordJohnson(largeElements);

	
	std::vector<Pair> orderedPairs =
		reorderPairs(pairs, largeElements);

	std::vector<int> mainChain =
		buildMainChain(orderedPairs);

	insertPending(mainChain, orderedPairs);

	if (hasStraggler)
	{
		std::vector<int>::iterator insertPosition =
			std::lower_bound(
				mainChain.begin(),
				mainChain.end(),
				straggler
			);

		mainChain.insert(insertPosition, straggler);
	}
	data = mainChain;
}

//deque 

std::deque<size_t> PmergeMe::generateDequeJacobsthalOrder(size_t size)
{
	std::deque<size_t> order;
	if (size <= 1)
		return order;
	size_t previousJacob = 1;
	size_t currentJacob = 3;
	size_t lastInserted = 1;
	while (lastInserted < size)
	{
		size_t upper = currentJacob;
		if (upper > size)
			upper = size;
		for (size_t i = upper; i > lastInserted; --i)
			order.push_back(i - 1);
		lastInserted = upper;
		size_t nextJacob =
			currentJacob + (2 * previousJacob);
		previousJacob = currentJacob;
		currentJacob = nextJacob;
	}
	return order;
}

std::deque<int> PmergeMe::extractLargeElements(const std::deque<Pair>& pairs)
{
	std::deque<int> largeElements;

	size_t size = pairs.size();
	for (size_t i = 0; i < size; ++i)
		largeElements.push_back(pairs[i].large);

	return largeElements;
}

std::deque<PmergeMe::Pair>
PmergeMe::generatePairs(const std::deque<int>& data)
{
	std::deque<Pair> pairs;

	size_t size = data.size();
	for (size_t i = 0; i + 1 < size; i += 2)
	{
		Pair pair;

		if (data[i] < data[i + 1])
		{
			pair.small = data[i];
			pair.large = data[i + 1];
		}
		else
		{
			pair.small = data[i + 1];
			pair.large = data[i];
		}

		pairs.push_back(pair);
	}

	return pairs;
}

std::deque<PmergeMe::Pair> PmergeMe::reorderPairs(std::deque<Pair>& pairs, const std::deque<int>& largeElements)
{
	std::deque<Pair> orderedPairs;

	size_t	elementSize = largeElements.size();
	size_t	pairsSize = pairs.size();

	for (size_t i = 0; i < elementSize; ++i)
	{
		for (size_t j = 0; j < pairsSize; ++j)
		{
			if (pairs[j].large == largeElements[i])
			{
				orderedPairs.push_back(pairs[j]);
				break;
			}
		}
	}

	return orderedPairs;
}

std::deque<int> PmergeMe::buildMainChain(const std::deque<Pair>& orderedPairs)
{
	std::deque<int> mainChain;

	if (orderedPairs.empty())
		return mainChain;

	mainChain.push_back(orderedPairs[0].small);

	size_t size = orderedPairs.size();
	for (size_t i = 0; i < size; ++i)
		mainChain.push_back(orderedPairs[i].large);

	return mainChain;
}
void PmergeMe::insertPending(
	std::deque<int>& mainChain,
	const std::deque<Pair>& pairs)
{
	size_t pairsSize = pairs.size();
	std::deque<size_t> insertionOrder =
		generateDequeJacobsthalOrder(pairsSize);

	size_t size = insertionOrder.size();
	
	for (size_t i = 0; i < size; ++i)
	{
		size_t pairIndex = insertionOrder[i];

		if (pairIndex >= pairsSize)
			continue;

		int pendingValue = pairs[pairIndex].small;
		int pairedValue = pairs[pairIndex].large;

		std::deque<int>::iterator pairedPosition =
			std::find(
				mainChain.begin(),
				mainChain.end(),
				pairedValue
			);

		std::deque<int>::iterator insertPosition =
			std::lower_bound(
				mainChain.begin(),
				pairedPosition,
				pendingValue
			);

		mainChain.insert(insertPosition, pendingValue);
	}
}

void PmergeMe::fordJohnson(std::deque<int>& data)
{
	size_t size = data.size();
	if (size <= 1)
		return;

	bool hasStraggler = (size % 2 != 0);
	int straggler = hasStraggler ? data.back() : 0;

	std::deque<Pair> pairs = generatePairs(data);

	std::deque<int> largeElements = extractLargeElements(pairs);

	fordJohnson(largeElements);

	
	std::deque<Pair> orderedPairs =
		reorderPairs(pairs, largeElements);

	std::deque<int> mainChain =
		buildMainChain(orderedPairs);

	insertPending(mainChain, orderedPairs);

	if (hasStraggler)
	{
		std::deque<int>::iterator insertPosition =
			std::lower_bound(
				mainChain.begin(),
				mainChain.end(),
				straggler
			);

		mainChain.insert(insertPosition, straggler);
	}
	data = mainChain;
}