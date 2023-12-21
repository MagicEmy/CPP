/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/28 19:09:04 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/11 17:28:59 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    {
        Array<int> tmp = numbers; // assignment of the array
        Array<int> test(tmp); // create a copy of the array
		/*modifying one of the two arrays after copy/assignment won’t affect
        anything in the other array.*/
		std::cout << std::endl;
        std::cout << "test[1]	: " << test[1] << std::endl;
        test[1] = 5; // modify the first element of the original
        std::cout << "test[1]	: "<< test[1] << std::endl;
        std::cout << "tmp[1]	: "<< tmp[1] << std::endl;
        tmp[1] = 10; // modify the first element of the copy
        std::cout << "test[1]	: "<< test[1] << std::endl;
        std::cout << "tmp[1]	: "<< tmp[1] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << std::endl;
	//extra test
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