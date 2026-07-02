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
	if(checkInput(input))
		throw std::runtime_error("Error");
	print();
}

int PmergeMe::checkInput(const std::vector<std::string> &input) {
	std::set<int> seen;
	for(size_t i = 0; i < input.size(); i++)
	{
		if (input[i].find_first_not_of("0123456789") != std::string::npos)
			return (1);
		if (input[i].length() > 10 ||
			(input[i].length() == 10 && input[i] > "2147483647"))
			return (1);
		int value = std::atoi(input[i].c_str());
		if (!seen.insert(value).second)
			return (1);
		_vector.push_back(value);
		_deque.push_back(value);
	}
	return (0);
}

void PmergeMe::print() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	sortVector();
	clock_t end = clock();

	std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : "
		<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

void PmergeMe::sortVector() {
	fordJohnson(_vector);
	
}

void PmergeMe::fordJohnson(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

	//separate pairs and sort them
	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		if (data[i] > data[i + 1])
			std::swap(data[i], data[i + 1]);
	}

	//separate the main chain and the pending elements
	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i + 1 < data.size(); i += 2)
	{
		pending.push_back(data[i]);      // smaller
		mainChain.push_back(data[i + 1]); // larger
	}

	bool hasStraggler = (data.size() % 2);
	int straggler = 0;

	if (hasStraggler)
		straggler = data.back();

    // 3. Recursively sort mainChain
    fordJohnson(mainChain);

    // 4. Insert pending elements

    // 5. Insert straggler

    // 6. data = mainChain;
}