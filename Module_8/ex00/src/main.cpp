#include "easyfind.hpp"

int main() {
	srand(time(NULL));
	try 
	{
		
		std::vector<int> vectorToCheck;
		for (int i = 0; i < 5; i++) {
			int randNum = rand() % 5;
			std::cout << "Added to the vector[" << i << "] > " << randNum
						<< std::endl;
			vectorToCheck.push_back(randNum);
		}
		int randNumToBeFound = rand() % 7;
		std::cout << "Trying to find in the vector value >> " << randNumToBeFound
				<< std::endl;
		easyfind(vectorToCheck, randNumToBeFound);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::list<int> listToCheck;
		for (int i = 0; i < 5; i++) {
			int randNum = rand() % 5;
			std::cout << "Added to the list[" << i << "] > " << randNum
						<< std::endl;
			listToCheck.push_back(randNum);
		}
		int randNumToBeFound = rand() % 7;
		std::cout << "Trying to find in the list value >> " << randNumToBeFound
				<< std::endl;
		easyfind(listToCheck, randNumToBeFound);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
		try
	{
		std::deque<int> dequeToCheck;
		for (int i = 0; i < 5; i++) {
			int randNum = rand() % 5;
			std::cout << "Added to the deque[" << i << "] > " << randNum
						<< std::endl;
			dequeToCheck.push_back(randNum);
		}
		int randNumToBeFound = rand() % 7;
		std::cout << "Trying to find in the deque value >> " << randNumToBeFound
				<< std::endl;
		easyfind(dequeToCheck, randNumToBeFound);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
