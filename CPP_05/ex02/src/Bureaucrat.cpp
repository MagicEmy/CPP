/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:00:22 by emlicame          #+#    #+#             */
/*   Updated: 2023/08/02 11:00:51 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name (" "), _grade(0) { 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name (name) {
	
	if ( grade < highestGrade )
		throw GradeTooLowException();
	else if ( grade > lowestGrade )
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat (void ) {}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name (src._name), 
												_grade (src._grade) {
	*this = src;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src) {
	if (this == &src)
		return (*this);
		
	const_cast<std::string&>(_name) = src._name;
	return (*this);
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increment( void ) {
	if (this->_grade - 1 < highestGrade)
		throw GradeTooLowException();
	_grade--;
}

void Bureaucrat::decrement( void ) {
	if (this->_grade + 1 > lowestGrade)
		throw GradeTooHighException();
	_grade++;
}

void Bureaucrat::signForm( AForm& src) {
	
	try
	{
		src.beSigned(*this);
		std::cout << this->getName() << " signed " << src.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << src.getName() << " : ";
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form){
	
	try
	{
		form.execute(*this);
		 std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

/* --------------- Non-Member Functions --------------- */

std::ostream& operator << (std::ostream& stream, const Bureaucrat& src)
{
    stream << "Name: " << src.getName() << ", bureaucrat grade: " << src.getGrade();
    return stream;
}