/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:50:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 15:58:35 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ){
}

Intern::~Intern (void ) {}

Intern::Intern(const Intern& src) {
	*this = src;
}

Intern& Intern::operator = (const Intern& src) {
	if (this == &src)
		return (*this);		
	return (*this);
}

const char* Intern::FormNotFound::what() const throw(){
	return ("The form chosen does not exist");
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
	
	std::string forms[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	int level = 4;
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			level = i;
			std::cout << "Intern creates " << forms[i] << std::endl;
		}
	}
	try{
		switch (level)
		{
			case 0:
				return new ShrubberyCreationForm( target );
			case 1:			
				return new RobotomyRequestForm( target );
			case 2:
				return  new PresidentialPardonForm( target );
			default :
				throw FormNotFound();
		}
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (nullptr);
}
