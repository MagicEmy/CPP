/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:00:22 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 13:03:15 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name (" "), _grade(0) { 
	std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name (name) {
	
	if ( grade < highestGrade )
		throw GradeTooLowException(); // Throwing an instance of the exception
	else if ( grade > lowestGrade )
		throw GradeTooHighException();
	else
		_grade = grade;

	std::cout << "Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat (void ) {
	std::cout << "Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) : _name (source._name), 
												_grade (source._grade) {
	*this = source;
	std::cout << "copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& source) {
	if (this == &source)
		return (*this);
		
	const_cast<std::string&>(_name) = source._name;
	return (*this);
	std::cout << "copy assignment operator" << std::endl;
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

void Bureaucrat::signForm( Form& source) {
	
	try
	{
		source.beSigned(*this);
		std::cout << this->getName() << " signed " << source.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << source.getName() << " : ";
		std::cerr << e.what() << std::endl;
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