/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:12:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 13:42:15 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>

//forward declaration for circular dependency"
class Bureaucrat;

class AForm
{
	private:
			const std::string _name;
			bool _signed;
			const int _gradeRequiredToSign;
			const int _gradeRequiredToExec;
	public:
			AForm( void );
			AForm( std::string name, int gSigned, int gExecuted );
			AForm(const AForm &src);
			virtual ~AForm( void );
			AForm& operator = (const AForm &src);
			
			const std::string& getName() const;
			bool getIfSigned( void ) const;
			int getGradeRequiredToSign( void ) const;
			int getGradeRequiredToExec( void ) const;

			void beSigned( const Bureaucrat& source );
			void checkExecution(const Bureaucrat & executor) const ;
			virtual void execute(Bureaucrat const & executor) const = 0;
			
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
			class FormNotSigned : public std::exception
			{						
				public:
					virtual const char* what() const throw();
			};
			
};

std::ostream & operator<<(std::ostream &stream, AForm const &src);

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