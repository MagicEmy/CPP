/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:19:12 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 13:47:43 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name(" "), _signed(false), _gradeRequiredToSign(0), 
						_gradeRequiredToExec(0){
}

AForm::AForm( std::string name, int gToSign, int gToExecute) : _name(name), _signed(false), 
																_gradeRequiredToSign(gToSign), 
																_gradeRequiredToExec(gToExecute) {
	if (_gradeRequiredToSign < 1 || _gradeRequiredToExec < 1)
		throw GradeTooLowException();
	else if (_gradeRequiredToSign > 150 || _gradeRequiredToExec > 150)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& src): _name(src._name), _signed(false), 
							_gradeRequiredToSign(src._gradeRequiredToSign), 
							_gradeRequiredToExec(src._gradeRequiredToExec){
	*this = src;
}

AForm::~AForm( void ){}

AForm& AForm::operator=(const AForm& src)
{
	if (this == &src)
		return (*this);
		
	const_cast<std::string &>(this->_name) = src._name;
	this->_signed = src._signed;
	const_cast<int &>(this->_gradeRequiredToSign) = src._gradeRequiredToSign;
	const_cast<int &>(this->_gradeRequiredToExec) = src._gradeRequiredToExec;
	return (*this);
}//or simply update the non-const member _signed:

const std::string& AForm::getName( void ) const {
	return _name;
}

int AForm::getGradeRequiredToSign( void ) const {
	return _gradeRequiredToSign;
}

int AForm::getGradeRequiredToExec( void ) const {
	return _gradeRequiredToExec;
}

bool AForm::getIfSigned( void ) const {
	return _signed;
}

void AForm::beSigned( const Bureaucrat& source) {
	if (source.getGrade() >  _gradeRequiredToSign )
		throw GradeTooLowException();
	_signed = true;
}

void AForm::checkExecution(const Bureaucrat & executor) const {
	if (!_signed)
		throw FormNotSigned();
	if (executor.getGrade() >  _gradeRequiredToSign )
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw() {
	return "Form not signed";
}

std::ostream& operator << (std::ostream& stream, AForm const &src)
{
	stream 	<< "Name: " << src.getName() << "\nSigned: " << src.getIfSigned() 
		<< "\nGrade Signed: " << src.getGradeRequiredToSign()	
		<< "\nGrade Executed: " << src.getGradeRequiredToExec() <<  std::endl;
	return (stream);
}