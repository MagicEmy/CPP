/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/27 17:03:29 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/29 11:09:03 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

int main( void )
{
	// std::vector<int> vec = {1, 2, 3, 4, 5};
	std::vector<int> loopVec;
	for (int i = 0; i < 5; i++)
		loopVec.push_back(i);
	
	int vecValue = 3;

	try {
		std::vector<int>::iterator result = easyfind(loopVec, vecValue);
		size_t vecIndex = std::distance(loopVec.begin(), result);
		std::cout << "Value in vector " << *result << " found at index " << vecIndex << std::endl;
	} 
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::list<int> myList = {10, 20, 30, 40, 50};
	int listValue = 50;
	
	try {
		auto listResult = easyfind(myList, listValue);
		size_t listIndex = std::distance(myList.begin(), listResult);
		std::cout << "Value in list " << *listResult << " found at index " << listIndex << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::list<int> listLoop;
	int listLoopVal = 30;
	
	for (int i = 5; i <= 50; i += 5) {
		listLoop.push_back(i);
	}

	try {
		std::list<int>::iterator loopResult = easyfind(listLoop, listLoopVal);
		size_t listIndex = std::distance(listLoop.begin(), loopResult);
		std::cout << "Value in list2 " << *loopResult << " found at index " << listIndex << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::deque<int> deq;
	for (int i = 0; i < 100; i += 10)
		deq.push_back(i);
	int deqVal = 70;

	try
	{
		std::deque<int>::iterator deqRes = easyfind(deq, deqVal);
		size_t deqIndex = std::distance(deq.begin(), deqRes);
		std::cout << "Value in deque " << *deqRes << " found at index " << deqIndex << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::set<int> setCon;
	for (int i = 0; i < 20; i++)
		setCon.insert(i);
	int setVal = 11;

	try
	{
		std::set<int>::iterator setRes = easyfind(setCon, setVal);
		size_t setIndex = std::distance(setCon.begin(), setRes);
		std::cout << "Value in set " << *setRes << " found at index " << setIndex << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}