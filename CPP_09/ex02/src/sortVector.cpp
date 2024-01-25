#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>


typedef std::pair<int,int>	pair;

//binary insertion sort.It inserts a new item (newItem) into the vector while maintaining the sorted order up to max_range.	std::upper_bound is used to find the position
void binaryInsert(std::vector<int>& vect, int newItem, unsigned int max_range)  {
	std::vector<int>::iterator iter = std::upper_bound(vect.begin(), vect.begin() + max_range, newItem);
	vect.insert(iter, newItem);
}

// merging operation using pairs in sorted(A) and toSort(B). It uses the Jacobsthal sequence to determine the insertion points for the elements in toSort into the sorted vector.
void PmergeMe::mergeInsert(const std::vector<int>& input, std::vector<int>& sorted, std::vector<int>& toSort) {

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
    // If the input vector size is odd
    if (input.size() % 2)
        binaryInsert(sorted, input.back(), input.size() - 1);
}

// takes a vector of pairs and sorts it based on the first element of each pair in descending order using the insertion sort algorithm.
void	sortVectPairs(std::vector<pair>& unsorted)
{
	int j;

	for (size_t i = 1; i < unsorted.size(); i++)
	{
		//compares pairs of elements
		j = i - 1;
		//if the first component of the pair at index j is less than the first component of the pair at index j + 1
		while ((j >= 0) && (unsorted[j].first < unsorted[j + 1].first))	{

			std::swap(unsorted[j + 1], unsorted[j]);
			j--;
		}
	}
	//toSort will be sorted in descending order based on the first component of the pairs.
}
//takes a vector of integers (vectInput), splits it into pairs, and then sorts those pairs using the sortVectPairs function. The sorted values are stored in two separate vectors (sorted and toSort).
void PmergeMe::splitAndSortVect(const std::vector<int>& vectInput, std::vector<int>& sorted, std::vector<int>& toSort )
{
	unsigned int		numPairs = vectInput.size() / 2;
	std::vector<pair>	vectPairs;

	// splitting the input vector vectInput into pairs, each pair is sorted in descending order.
	for (unsigned int i = 0; i < numPairs; i++)
	{
		//if the first element of the current pair is greater than the second element.
		if (vectInput[i * 2] > vectInput[i * 2 + 1])
			vectPairs.push_back(pair(vectInput[i * 2], vectInput[i * 2 + 1]));
		else
			vectPairs.push_back(pair(vectInput[i * 2 + 1], vectInput[i * 2]));
			//If the second element is >= , a pair is constructed with the elements swapped, larger element is the first in the pair. 
	}

	sortVectPairs(vectPairs);
	for (int i = numPairs - 1; i >= 0; i--)
	{
		sorted.push_back(vectPairs[i].first);
		toSort.push_back(vectPairs[i].second);
	}
}

