/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:10 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 13:04:10 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	{
	try
	{
		Bureaucrat Vogon_1("Ugly Alien", 1);
		Form form_1("Eval_1", 10, 9);	
		std::cout << Vogon_1 << std::endl;
		std::cout << form_1 << std::endl;
		Vogon_1.signForm(form_1);
		std::cout << "\n*************" << std::endl;
		Vogon_1.increment();
		std::cout << Vogon_1 << std::endl;
		std::cout << form_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	}

	try
	{
		Bureaucrat Vogon_2("Old Alien", 15);
		Form form_2("Eval_2", 10, 9);	
		std::cout << Vogon_2 << std::endl;
		std::cout << form_2 << std::endl;
		
		Vogon_2.signForm(form_2);
		std::cout << "\n++++++++++++++++" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	// try
	// {
	// 	Bureaucrat Vogon_3("Grumpy Alien", 151);
	// 	std::cout << Vogon_3 << std::endl;
	
	// 	Vogon_3.decrement();
	// 	std::cout << Vogon_3 << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }	
	
	return (0);
}

