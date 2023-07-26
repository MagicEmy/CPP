/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:19:12 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 13:01:33 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name(" "), _signed(false), _gradeRequired(0), _gradeExecuted(0){
	std::cout << "Deafault constructor" << std::endl;
}

Form::Form( std::string name, int gSigned, int gExecuted) : _name(name), _signed(false), 
																	_gradeRequired(gSigned), 
																	_gradeExecuted (gExecuted) {
	if (_gradeRequired < 1 || _gradeExecuted < 1)
		throw GradeTooLowException();
	else if (_gradeRequired > 150 || _gradeExecuted > 150)
		throw GradeTooHighException();
	std::cout << "Deafault constructor" << std::endl;
}

Form::Form(const Form& source): _name(source._name), _signed(false), 
							_gradeRequired(source._gradeRequired), _gradeExecuted(source._gradeExecuted){
	*this = source;
}

Form::~Form( void ){
	std::cout << "Destructor" << std::endl;
}

Form& Form::operator=(const Form& source)
{
	if (this == &source)
		return (*this);
		
	const_cast<std::string &>(this->_name) = source._name;
	this->_signed = source._signed;
	const_cast<int &>(this->_gradeRequired) = source._gradeRequired;
	const_cast<int &>(this->_gradeExecuted) = source._gradeExecuted;
	return (*this);
}//or simply update the non-const member _signed:

const std::string& Form::getName( void ) const {
	return _name;
}

int Form::getGradeRequired( void ) const {
	return _gradeRequired;
}

int Form::getGradeExecuted( void ) const {
	return _gradeExecuted;
}

bool Form::getIfSigned( void ) const {
	return _signed;
}

/*It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.*/
void Form::beSigned( const Bureaucrat& source) {
	if (source.getGrade() >  _gradeRequired )
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

std::ostream& operator << (std::ostream& stream, Form const &src)
{
	stream 	<< "Name: " << src.getName() << "\nSigned: " << src.getIfSigned() 
		<< "\nGrade Signed: " << src.getGradeRequired()	
		<< "\nGrade Executed: " << src.getGradeExecuted() <<  std::endl;
	return (stream);
}