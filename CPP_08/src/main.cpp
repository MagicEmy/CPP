/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/27 17:03:29 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/27 17:58:34 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void )
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	int value = 3;

	try {
		auto result = easyfind(vec, value);
		std::cout << "Value in vector " << *result << " found at memory address " << &result << std::endl;
	} 
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::list<int> myList = {10, 20, 30, 40, 50};
	int valueList = 50;
	
	try {
		auto listResult = easyfind(myList, valueList);
		std::cout << "Value in list " << *listResult << " found at memory address " << &listResult << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::list<int> listLoop;
	int valueLoop = 30;
	
	for (int i = 0; i <= 50; i += 5) {
		listLoop.push_back(i);
	}

	try {
		auto loopResult = easyfind(listLoop, valueLoop);
		std::cout << "Value in list 2 " << *loopResult << " found at memory address " << &loopResult << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}