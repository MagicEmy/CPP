/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:50:52 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 19:09:23 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", \
													_signGrade, _executeGrade),
													_target (" "){
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", \
																_signGrade, _executeGrade),
																_target (target){
}

RobotomyRequestForm::~RobotomyRequestForm( void ){
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src) : 
											AForm("RobotomyRequestForm", _signGrade, _executeGrade),
											_target (src._target){
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
	if (this == &src)
		return (*this);
	this->_target = src._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	checkExecution(executor);
	std::cout << "Bzz...bzz...bzzzzzzzzzz\n";
	std::srand((unsigned int)time(NULL));
	int randomRet = std::rand() % 2;
	if (randomRet)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " robotomy failed." << std::endl;
}

/*
The reason for using srand with time(NULL) is to initialize the random number 
generator with a different seed each time the program is run, 
creating a new sequence of random numbers. Without setting a new seed each time, 
the random number sequence would be the same in each program execution, 
leading to the same outcome repeatedly, 
which is not desired for simulating randomness.*/