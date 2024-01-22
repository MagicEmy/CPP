#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <cstdlib>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }

    std::vector<int> vecSequence;
    std::list<int> listSequence;

    for (int i = 1; i < argc; ++i) {
        try {
            int num = std::stoi(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative number");
			}
            vecSequence.push_back(num);
            listSequence.push_back(num);
        } catch (const std::exception& e) {
            std::cerr << "Error: Invalid input sequence" << std::endl;
            return 1;
        }
    }

    // Display unsorted sequences
    PmergeMe::displaySequence(vecSequence, "Before");
    PmergeMe::displaySequence(listSequence, "Before");

    // Sort using Ford-Johnson algorithm for vectors
    // PmergeMe::fordJohnsonSort(vecSequence);

    // // Sort using Ford-Johnson algorithm for lists
    // PmergeMe::fordJohnsonSort(listSequence);

    // // Display sorted sequences
    // PmergeMe::displaySequence(vecSequence, "After");
    // PmergeMe::displaySequence(listSequence, "After");

    return 0;
}