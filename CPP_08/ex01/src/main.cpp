/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 11:57:01 by emlicame      #+#    #+#                 */
/*   Updated: 2024/01/02 17:29:48 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <numeric>

int main ( void )
{
	std::cout << "New object called sp, max size 5:" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// Printing elements
    std::cout << "Printing vector in object sp:" << std::endl;
    for (size_t i = 0; i < sp._spanVec.size(); ++i) {
        std::cout << sp._spanVec[i] << " ";
    }
    std::cout << std::endl;
	
	try
	{
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nNew object called sp2, max size 50:" << std::endl;
	Span sp2(50);
	try {
		sp2.addNumber(5);
		sp2.addNumber(12);
        sp2.fillRangeInSpan(20, 30);
		std::cout << "\nPrinting vector after filling a range of integers:" << std::endl;
		for (size_t i = 0; i < sp2._spanVec.size(); ++i) {
			std::cout << sp2._spanVec[i] << " ";
		}
		std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	try {
		std::cout << "\ntrying to fill over the max, range 0 to 70: " << std::endl;
        sp2.fillRangeInSpan(0, 70);
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	
	std::vector<int> additionalNumbers(100); // Creating a vector to hold 51 integers
    // Use std::iota to fill the vector with numbers from startValue until the end or the value given as the end of the range
    int startValue = 0;
    std::iota(additionalNumbers.begin(), additionalNumbers.end(), startValue);

    try {
		std::cout << "\ntrying to fill with wrong range, range 35 to 25: " << std::endl;
        sp2.addRange(additionalNumbers.begin() + 35, additionalNumbers.begin() + 25 + 1);
		std::cout << "\nCurrent vector" << std::endl;
		for (size_t i = 0; i < sp2._spanVec.size(); ++i) {
			std::cout << sp2._spanVec[i] << " ";
		}
		std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	

	try {
		std::cout << "\nFilling in vector with a range of integeres from 0 to 25: " << std::endl;
        sp2.addRange(additionalNumbers.begin(), additionalNumbers.begin() + 25 + 1);
		std::cout << "\nVector" << std::endl;
		for (size_t i = 0; i < sp2._spanVec.size(); ++i) {
			std::cout << sp2._spanVec[i] << " ";
		}
		std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	

	std::cout << "\nNew object called spThousends, max size 200000:" << std::endl;
	Span spThousends(200000);

	try {
		std::cout << "\ntrying to fill over the max, range 0 to 70: " << std::endl;
        spThousends.fillRangeInSpan(0, 100000);
		std::cout << "\nPrinting vector after filling a range of integers:" << std::endl;
		// for (size_t i = 0; i < spThousends._spanVec.size(); ++i) {
		for (size_t i = 0; i < 100; ++i) {
			std::cout << spThousends._spanVec[i] << " ";
		}
		std::cout << spThousends._spanVec[spThousends._spanVec.size() - 1] << " ";
		std::cout << std::endl;
		
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

	
	return 0;
}