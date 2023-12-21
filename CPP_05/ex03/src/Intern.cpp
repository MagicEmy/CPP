/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:50:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/08/02 11:17:23 by emlicame         ###   ########.fr       */
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
	int level; 
	for (level = 0; level < 3; level++)
	{
		if (forms[level] == formName)
		{
			std::cout << "Intern creates " << forms[level] << std::endl;
			break;
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
