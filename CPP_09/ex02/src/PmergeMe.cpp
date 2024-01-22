#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

namespace PmergeMe {
    using namespace std;
    using namespace chrono;

	// template <typename Container>
    // void displaySequence(const Container& sequence, const std::string& message) {
    
	// 	std::cout << message << ": ";

    // 	// Using iterators to iterate over the container
    // 	for (typename Container::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
    //     	std::cout << *it << " ";
    // 	}

    // 	std::cout << std::endl;
	// }

	void displaySequence(const std::vector<int>& sequence, const std::string& message) {
		std::cout << message << ": ";
		
    	// Using iterators to iterate over the container
    	for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        	std::cout << *it << " ";
    	}

    	std::cout << std::endl;
	}

	void displaySequence(const std::list<int>& sequence, const std::string& message) {
		std::cout << message << ": ";

		for (std::list<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        	std::cout << *it << " ";
    	}


		std::cout << std::endl;
	}

    void displayTime(const Clock::time_point& start, const Clock::time_point& end, const string& containerType) {
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Time to process a range with " << containerType << " : " << duration << " us" << endl;
    }

    // void fordJohnsonSort(vector<int>& sequence) {
    //     Clock::time_point start = Clock::now();

        // Implement Ford-Johnson sort for vector
        // (Replace this with your Ford-Johnson algorithm implementation)

    //     Clock::time_point end = Clock::now();
    //     displayTime(start, end, "std::vector");
    // }

    // void fordJohnsonSort(list<int>& sequence) {
    //     Clock::time_point start = Clock::now();

        // Implement Ford-Johnson sort for list
        // (Replace this with your Ford-Johnson algorithm implementation)

//         Clock::time_point end = Clock::now();
//         displayTime(start, end, "std::list");
//     }
}