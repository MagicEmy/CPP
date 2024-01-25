#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>


typedef std::pair<int, int> pair;

//binary insertion sort.It inserts a new item (newItem) into the vector while maintaining the sorted order up to max_range.	std::upper_bound is used to find the position
void binaryInsert(std::deque<int>& deq, int newItem, unsigned int max_range) {
    std::deque<int>::iterator iter = std::upper_bound(deq.begin(), deq.begin() + max_range, newItem);
    deq.insert(iter, newItem);
}

// Merging operation using the sorted deques toSort and sorted. It uses a modified version of the Jacobsthal sequence to determine the insertion points for the elements in toSort into the sorted deque. The merging is done in such a way that the final sorted deque is sorted.
void PmergeMe::mergeInsertDeque(const std::deque<int>& input, std::deque<int>& sorted, std::deque<int>& toSort) {

    unsigned int nPairs = input.size() / 2;
    unsigned int inserted = 0;

    if (toSort.empty())
        return;

    binaryInsert(sorted, toSort[0], inserted++);

	for (std::vector<int>::iterator it = _jacobsthalNumbers.begin() + 1; it != _jacobsthalNumbers.end(); ++it) {
		if (*it < 5){
	    	for (int x = std::min<int>(*it, nPairs - 1); x > 0 && x >= *(it - 1); x--) 
    	  		binaryInsert(sorted, toSort[x], inserted++ + x);
		}
		else {
			for (int x = std::min<int>(*it, nPairs - 1); x > 0 && x > *(it - 1); x--)
				binaryInsert(sorted, toSort[x], inserted++ + x);
		}
	}

    // If the input deque size is odd, insert the last element into 'sorted'
    if (input.size() % 2)
        binaryInsert(sorted, input.back(), input.size() - 1);
}

// Takes a deque of pairs (toSort) and sorts it based on the first element of each pair in descending order using the insertion sort algorithm. The sorting is done in-place.
void sortVectPairs(std::deque<pair>& unsorted) {
    int j;

    for (size_t i = 1; i < unsorted.size(); i++) {
        // Compares pairs of elements
        j = i - 1;
        // If the first component of the pair at index j is less than the first component of the pair at index j + 1
        while ((j >= 0) && (unsorted[j].first < unsorted[j + 1].first)) {
            std::swap(unsorted[j + 1], unsorted[j]);
            j--;
        }
    }
    // toSort will be sorted in descending order based on the first component of the pairs.
}

// Takes a deque of integers (dequeInput), splits it into pairs, and then sorts those pairs using the sortVectPairs function. The sorted values are stored in two separate deques (sorted and toSort).
void PmergeMe::splitAndSortDeque(const std::deque<int>& dequeInput, std::deque<int>& sorted, std::deque<int>& toSort) {
    // Find the number of pairs in deque
    unsigned int numPairs = dequeInput.size() / 2;
    std::deque<pair> dequePairs;

    // Splitting the input deque dequeInput into pairs, each pair is sorted in descending order.
    for (unsigned int i = 0; i < numPairs; i++) {
        // If the first element of the current pair is greater than the second element.
        if (dequeInput[i * 2] > dequeInput[i * 2 + 1])
            dequePairs.push_back(pair( dequeInput[i * 2], dequeInput[i * 2 + 1] ));
        else
            dequePairs.push_back(pair( dequeInput[i * 2 + 1], dequeInput[i * 2] ));
            // If the second element is >=, a pair is constructed with the elements swapped, larger element is the first in the pair.
    }
    
    sortVectPairs(dequePairs);
    for (int i = numPairs - 1; i >= 0; i--) {
        sorted.push_back(dequePairs[i].first);
        toSort.push_back(dequePairs[i].second);
    }
}
