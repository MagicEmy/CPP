/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:00:22 by emlicame          #+#    #+#             */
/*   Updated: 2023/08/02 10:58:15 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name (" "), _grade(0) { 
	// std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name (name) {
	
	if ( grade < 1 )
		throw GradeTooLowException(); // Throwing an instance of the exception
	else if ( grade > 150 )
		throw GradeTooHighException();
	else
		_grade = grade;

	// std::cout << "Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat (void ) {
	// std::cout << "Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) : _name (source._name), 
												_grade (source._grade) {
	*this = source;
	// std::cout << "copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& source) {
	if (this == &source)
		return (*this);
		
	const_cast<std::string&>(_name) = source._name;
	return (*this);
	// std::cout << "copy assignment operator" << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increment( void ) {
	if (this->_grade - 1 < 1)
		throw GradeTooLowException();
	_grade--;
}

void Bureaucrat::decrement( void ) {
	if (this->_grade + 1 > 150)
		throw GradeTooHighException();
	_grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

/* --------------- Non-Member Functions --------------- */

std::ostream& operator << (std::ostream& output, const Bureaucrat& source)
{
    output << "Name: " << source.getName() << ", bureaucrat grade: " << source.getGrade();
    return output;
}