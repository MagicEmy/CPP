/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 11:39:30 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/22 19:29:34 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <cstring>

int main( void ) {
{
	std::cout << "INT array" << std::endl;
	int arrOne[] = {1, 2, 3, 4, 5};
	::iter(arrOne, sizeof(arrOne)/sizeof(arrOne[0]), func<int>);
	std::cout << std::endl;
}
{
	std::cout << "\nCHAR array" << std::endl;
	char arrTwo[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arrTwo, sizeof(arrTwo)/sizeof(arrTwo[0]), func<char>);
	std::cout << std::endl;
}
{
	std::cout << "\nSTRING array" << std::endl;
	const char *arrThree[] = {"I'm a shooting star", "leaping through the sky", "like a tiger"};
	::iter(arrThree, sizeof(arrThree)/sizeof(arrThree[0]), func<const char *>);
	std::cout << std::endl;
}
{
	std::cout << "\nDOUBLE array" << std::endl;
	double arrFour[] = {2.5, 35.6, 42.42, 8.3};
	::iter(arrFour, sizeof(arrFour)/sizeof(arrFour[0]), func<double>);
	std::cout << std::endl;
}
{
	std::cout << "\nCHAR non const - to Upper" << std::endl;
	char arrUp[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "before" << std::endl;
	::iter(arrUp, sizeof(arrUp)/sizeof(arrUp[0]), func<char>);
	std::cout << "\nafter" << std::endl;
	::iter(arrUp, sizeof(arrUp)/sizeof(arrUp[0]), toUpper<char>);
	std::cout << std::endl;
}
{
	std::cout << "\nSTRING - as class" << std::endl;
	std::string myName = "I'm Magic";
	::iter(&myName, 1, func<std::string>);
	std::cout << std::endl;
	std::string	myNames[] = {"My", "name", "is", "Magic"};
	::iter(myNames, sizeof(myNames) / sizeof(std::string), func<std::string>);
	std::cout << std::endl;
}
	char arrTwo[] = {'a', 'b', 'c', 'd', 'e'};
	iter<int>({}, 0, func<int>);
	iter(reinterpret_cast<char *>(NULL), 23, func<char>);
	iter(arrTwo, std::strlen(arrTwo), reinterpret_cast<void (*)(char&)>(NULL));

	return 0;
}