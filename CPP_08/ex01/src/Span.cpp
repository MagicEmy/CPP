/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 11:38:20 by emlicame      #+#    #+#                 */
/*   Updated: 2024/01/02 17:12:25 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>


Span::Span() : _maxSize(0) {}

Span::Span(int n) : _maxSize(n) {}

Span::Span(const Span &src) : _maxSize(src._maxSize) { *this = src; }

Span &Span::operator=(const Span &src) {

	if (this == &src)
		return *this;
	_maxSize = src._maxSize;
	return *this;
}

Span::~Span() {}

// ** Modifiers ** 

void Span::addNumber(int n) {

	if (_spanVec.size() >= _maxSize)
		throw ContainerFull();
	_spanVec.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	
	size_t rangeSize = std::distance(begin, end);
    if (_spanVec.size() + rangeSize > _maxSize) {
        throw ContainerFull();
    }
	if (begin > end) {
        throw WrongRange();
    }
    _spanVec.insert(_spanVec.end(), begin, end);
}

void Span::fillRangeInSpan(int start, int end) {
	if (_spanVec.size() + (end - start + 1) > _maxSize) {
		throw ContainerFull();
	}

	for (int i = start; i <= end; ++i) {
		_spanVec.push_back(i);
	}
}

int Span::shortestSpan( void ) {

	if (_spanVec.size() < 2)
		throw NoElements();

	std::sort(_spanVec.begin(), _spanVec.end());
	int shortest = _spanVec[1] - _spanVec[0];
	for (unsigned int i = 2; i <_spanVec.size(); i++) {
		shortest = std::min(shortest, _spanVec[i] - _spanVec[i - 1]);	
	}

	return shortest;
}

int Span::longestSpan( void ) {

	if (_spanVec.size() < 2)
		throw NoElements();

	return *std::max_element(_spanVec.begin(), _spanVec.end()) - *std::min_element(_spanVec.begin(), _spanVec.end());
}

const char* Span::ContainerFull::what() const throw() {
    return "Container is at full capacity";
}

const char* Span::NoElements::what() const throw() {
    return "Container does not contain enough elements";
}

const char* Span::WrongRange::what() const throw() {
    return "Wrong range insert: the begin must be less then the end";
}

/*	
some categories of algorithms:

Non-modifying sequence operations: These include algorithms like std::for_each, std::count, std::find, etc., 
which do not modify the elements of the container2.

Modifying sequence operations: These include algorithms like std::copy, std::move, std::replace, etc., 
which modify the elements of the container2.

Sorting and related operations: These include algorithms like std::sort, std::partial_sort, std::nth_element, etc., 
which are used for sorting and searching operations2.

Set operations (on sorted ranges): These include algorithms like std::merge, std::includes, std::set_union, etc., 
which perform operations on sorted ranges2.

Heap operations: These include algorithms like std::push_heap, std::pop_heap, std::make_heap, etc., 
which are used for operations on heaps2.

Minimum/maximum operations: These include algorithms like std::min, std::max, std::minmax, etc., 
which are used to find the minimum and maximum elements2.

*/