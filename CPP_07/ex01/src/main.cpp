/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 11:39:30 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/20 20:17:22 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void ) {

{
	std::cout << "INT array" << std::endl;
	int arrOne[] = {1, 2, 3, 4, 5};
	iter(arrOne, sizeof(arrOne)/sizeof(arrOne[0]), func);
	std::cout << std::endl;
}
{
	std::cout << "\nCHAR array" << std::endl;
	char arrTwo[] = {'a', 'b', 'c', 'd', 'e'};
	iter(arrTwo, sizeof(arrTwo)/sizeof(arrTwo[0]), func);
	std::cout << std::endl;

}
{
	std::cout << "\nSTRING array" << std::endl;
	const char *arrThree[] = {"I'm a shooting star", "leaping through the sky", "like a tiger"};
	iter(arrThree, sizeof(arrThree)/sizeof(arrThree[0]), func);
	std::cout << std::endl;
}

{
	std::cout << "\nDOUBLE array" << std::endl;
	double arrFour[] = {2.5, 35.6, 42.42, 8.3};
	iter(arrFour, sizeof(arrFour)/sizeof(arrFour[0]), func);
	std::cout << std::endl;
}

{
	std::cout << "\nSTRING to upper" << std::endl;
	const char *arrUp[] = {"It's a kind of magic"};
	iter(arrUp, sizeof(arrUp)/sizeof(arrUp[0]), toUpper);
	std::cout << std::endl;
}

	return 0;
}