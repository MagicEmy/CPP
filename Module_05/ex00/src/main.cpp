/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:10 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/20 16:56:31 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
	{
	try
	{
		Bureaucrat Vogon_1("Ugly Alien", 1);
		std::cout << Vogon_1 << std::endl;
	
		Vogon_1.increment();
		std::cout << Vogon_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}

	{
	try
	{
		Bureaucrat Vogon_2("Old Alien", 0);
		std::cout << Vogon_2 << std::endl;
	
		Vogon_2.increment();
		std::cout << Vogon_2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}
	
	{
	try
	{
		Bureaucrat Vogon_3("Grumpy Alien", 151);
		std::cout << Vogon_3 << std::endl;
	
		Vogon_3.decrement();
		std::cout << Vogon_3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	}
	
	return (0);
}

