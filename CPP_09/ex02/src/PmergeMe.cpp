#include "PmergeMe.hpp"
#include <iostream>
#include <set>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <climits>


typedef std::pair<int,int>	pair;

PmergeMe::PmergeMe() : _sequence(), _deSequence(), _jacobsthalNumbers(), _maxValue(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _sequence(src._sequence), _deSequence(src._deSequence), 
										_jacobsthalNumbers(src._jacobsthalNumbers), _maxValue(src._maxValue) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this == &src)
		return *this;
	this->_sequence = src._sequence;
	this->_deSequence = src._deSequence;
	this->_jacobsthalNumbers = src._jacobsthalNumbers;
	this->_maxValue = src._maxValue;
	return *this;
}

void PmergeMe::generateJacobsthalNumbers() {

    int a = 0;
    int b = 1;

    while (a <= this->_maxValue) {
	    _jacobsthalNumbers.push_back(a);
        int temp = a;
        a = b;
        b = b + 2 * temp;
    }
}

bool PmergeMe::hasDuplicates(std::vector<int>& vec) {
    std::set<int> s(vec.begin(), vec.end());
	if (!s.empty())
        this->_maxValue = *(s.rbegin());
    return s.size() < vec.size();
}

void isnumber(std::string str) {
    if (str.empty())
        throw std::runtime_error("Empty string");
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (isdigit(*it) == false)
            throw std::runtime_error("The input is not valid, please enter only positive numbers");    
    }
}

bool	PmergeMe::inputValidation(int argc, char **argv) {
	if (argc == 1)
		return (false);
	for (int i = 1; argv[i]; i++) {
		try {
			if (argv[i][0] == '+')
				argv[i]++;
			isnumber(argv[i]);
			if (std::stoi(argv[i]) > INT_MAX)
				throw std::out_of_range("number is too big");    
			_sequence.push_back(std::stoi(argv[i]));
		} catch (const std::exception& e) {
			throw;
		}
	}
	return (true);
}

void	PmergeMe::parse(int argc, char **argv) {

	try {
			inputValidation(argc, argv);
			if (hasDuplicates(_sequence))
        		throw std::runtime_error("Duplicate numbers found");
		} catch (const std::exception& e) {
			throw;
		}

	generateJacobsthalNumbers();
	_deSequence.assign(_sequence.begin(), _sequence.end());

	std::cout << "Input Before sorting: ";
	if (_sequence.size() > 20) {
		for (std::vector<int>::const_iterator it = _sequence.begin(); it != _sequence.begin() + 20; ++it) {
        	std::cout << *it << " "; }
		std::cout << "[...]";
		std::cout << std::endl;
		std::ofstream infile("input.txt");
		if (!infile.is_open())
			throw std::runtime_error("Error opening file");
		for (std::vector<int>::const_iterator it = _sequence.begin(); it != _sequence.end(); ++it) {
        	infile << *it << " ";
   		}
    	infile << std::endl;
		infile.close();
	}
	else {
		for (std::vector<int>::const_iterator it = _sequence.begin(); it != _sequence.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void	PmergeMe::run() {

	std::vector<int> sorted;
    std::vector<int> toSort;
	std::deque<int> dSorted;
    std::deque<int> dtoSort;

	auto startTime = std::chrono::high_resolution_clock::now();
	splitAndSortVect(_sequence, sorted, toSort);
	mergeInsertVect(_sequence, sorted, toSort);
	auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

	auto startTimeDeq = std::chrono::high_resolution_clock::now();
	splitAndSortDeque(_deSequence, dSorted, dtoSort);
	mergeInsertDeque(_deSequence, dSorted, dtoSort);
	auto endTimeDeq = std::chrono::high_resolution_clock::now();
    auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(endTimeDeq - startTimeDeq);

	std::cout << "Input  After sorting: ";

	if (_sequence.size() > 20) {
		for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.begin() + 20; ++it) {
        	std::cout << *it << " "; }
		std::cout << "[...]";
		std::cout << std::endl;
		std::ofstream outfile("output.txt");
		if (!outfile.is_open())
			throw std::runtime_error("Error opening file");
		for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it) {
        	outfile << *it << " ";
   		}
    	outfile << std::endl;
		outfile.close();
	}
	else {
		for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	displayTimeVec("vector", duration);
	displayTimeDeq("deque", durationDeq);
}

void PmergeMe::displayTimeVec(const std::string& containerType, const std::chrono::microseconds& duration) {
	
	std::cout << "Time to process a range of " << _sequence.size() << " elements with " << containerType
              << " : " << std::fixed << std::setprecision(5) << static_cast<double>(duration.count())/1000 << " microseconds" << std::endl;
}

void PmergeMe::displayTimeDeq(const std::string& containerType, const std::chrono::microseconds& duration) {
	
	std::cout << "Time to process a range of " << _deSequence.size() << " elements with " << containerType
              << " : " << std::fixed << std::setprecision(5) << static_cast<double>(duration.count())/1000 << " microseconds" << std::endl;
}



/*
Jacobsthal numbers are an integer sequence related to Fibonacci numbers. Similar to Fibonacci, where each term is the sum of the previous two terms, each term is the sum of the previous, plus twice the one before that. Traditionally the sequence starts with the given terms 0, 1.

   J0 = 0
   J1 = 1
   Jn = Jn-1 + 2 × Jn-2

Jacobsthal numbers are a sequence of integers where each number is the sum of twice the previous 
number and the number before that. 
0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525
binary insertion sort algorithm using Jacobsthal numbers as a guide for efficient insertion.

https://iq.opengenus.org/merge-insertion-sort/
https://rosettacode.org/wiki/Jacobsthal_numbers

*/
