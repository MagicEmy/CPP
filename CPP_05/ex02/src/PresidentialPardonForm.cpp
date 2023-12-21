/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:52:22 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 18:45:02 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", \
													_signGrade, _executeGrade), \
													_target (" "){	
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PresidentialPardonForm", \
																_signGrade, _executeGrade), \
																_target (target){
}

PresidentialPardonForm::~PresidentialPardonForm( void ){
	
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm("PresidentialPardonForm", \
													_signGrade, _executeGrade){	
	this->_target = src._target;
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm &src){
	if(this == &src)
		return (*this);
	this->_target = src._target;
	return (*this);
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{

	checkExecution(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}