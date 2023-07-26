/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:10 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 15:40:11 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{
	{
	Intern dummy;
	RobotomyRequestForm rf1("test1");
	ShrubberyCreationForm sc1("test2");
	try {
		// Bureaucrat b("Bureaucrat1", 10);
		// std::cout << b << std::endl;
		// std::cout << std::endl;
		// b.signForm(rf1);
		// std::cout << std::endl;
		// std::cout << rf1 << std::endl;

		// b.executeForm(rf1);
		// std::cout <<"\n";
		
		// b.signForm(sc1);
		// std::cout <<"\n";
		// b.executeForm(sc1);
		
		AForm *done;
		done = dummy.makeForm("PresidentialPardonForm", "test1");
		
		delete done;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Intern dummy2;
		AForm *done_2;
		done_2 = dummy2.makeForm("Bibuba", "test1");
		
		delete done_2;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	}
	
	// {
	// 	PresidentialPardonForm pf1("test1");
	// 	try {
	// 		Bureaucrat b("Bureaucrat1", 4);
	// 		std::cout << "\n" << b << std::endl;
	// 		std::cout << std::endl;
	// 		b.signForm(pf1);
	// 		std::cout << std::endl;
	// 		std::cout << pf1 << std::endl;
	// 		b.executeForm(pf1);
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }
}

