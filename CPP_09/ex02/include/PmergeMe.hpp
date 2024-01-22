#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <chrono>
#include <string>

namespace PmergeMe {
    using Clock = std::chrono::high_resolution_clock;

    void displaySequence(const std::vector<int>& sequence, const std::string& message);
	void displaySequence(const std::list<int>& sequence, const std::string& message);
    void displayTime(const Clock::time_point& start, const Clock::time_point& end, const std::string& containerType);

    // void fordJohnsonSort(std::vector<int>& sequence);
    // void fordJohnsonSort(std::list<int>& sequence);
}

#endif // PMERGEME_HPP
