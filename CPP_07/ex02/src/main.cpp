/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 19:09:04 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/22 19:29:58 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	//arrays initialization: type Array<int> called numbers and regular integer array mirror.
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	
	//Random integer values are generated and stored in both arrays (numbers and mirror).
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    {
        Array<int> tmp = numbers; // tmp is created as a copy of numbers
        Array<int> test(tmp); // create a copy of the array - test is assigned the value of tmp.
		/*modifying one of the two arrays after copy/assignment won’t affect
        anything in the other array.*/
		std::cout << std::endl;
        std::cout << "test[1] original: " << test[1] << std::endl;
        std::cout << "tmp[1] original	: "<< tmp[1] << std::endl;
        test[1] = 5; // modify the first element of the original
        std::cout << "\ntest[1] after modification : "<< test[1] << std::endl;
        tmp[1] = 10; // modify the first element of the copy
        std::cout << "temp[1]	after modification : "<< tmp[1] << std::endl;
        std::cout << "\nAgain together"<< std::endl;
        std::cout << "test[1] : " << test[1]  << "\ttmp[1] : " << tmp[1] <<std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "not the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << std::endl;
	
	//test empty
	try
	{
		Array<int>	empty;
		std::cout	<< "empty.size()\t"	<< empty.size()	<< std::endl;
		std::cout	<< empty[0]	<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//test out of bound
	try
    {
        std::cout << "---Negative index---" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << '\n';
    }
	
	std::cout << std::endl;
    try
    {
        std::cout << "---Index bigger than size---" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception :"<< e.what() << '\n';
    }
	
	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	
    delete [] mirror;
    return 0;
}



/*const std::exception& e
to catch all exceptions derived from std::exception, 
including the OutOfBounds

catch(const Array<int>::OutOfBounds &e) {
	std::cerr << "Caught OutOfBounds exception: " << e.what() << '\n';
*/