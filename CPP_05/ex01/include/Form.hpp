/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:12:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 13:42:49 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>

//forward declaration for circular dependency"
class Bureaucrat;

class Form
{
	private:
			const std::string _name;
			bool _signed;
			const int _gradeRequired;
			const int _gradeExecuted;
	public:
			Form( void );
			Form( std::string name, int gSigned, int gExecuted );
			Form(const Form &source);
			~Form( void );
			Form& operator = (const Form &source);
			
			const std::string& getName() const;
			bool getIfSigned( void ) const;
			int getGradeRequired( void ) const;
			int getGradeExecuted( void ) const;

			void beSigned( const Bureaucrat& source );
			
			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
			
			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
			
};

std::ostream & operator<<(std::ostream &stream, Form const &src);

#include "Bureaucrat.hpp"

#endif		//==============BUREAUCRAT_HPP	

/* 
class exception {
public:
  exception () throw();
  exception (const exception&) throw();
  exception& operator= (const exception&) throw();
  virtual ~exception() throw();
  virtual const char* what() const throw();
}

*/