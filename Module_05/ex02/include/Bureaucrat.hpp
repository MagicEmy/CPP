/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:55:51 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/24 18:52:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>

//forward declaration for circular dependency"
class AForm;

class Bureaucrat
{
	private:
			const std::string _name;
			int	_grade;
	public:
			Bureaucrat( void );
			Bureaucrat( std::string name, int grade );
			Bureaucrat(const Bureaucrat &src);
			virtual ~Bureaucrat( void );
			Bureaucrat& operator = (const Bureaucrat &src);
			
			const std::string& getName() const;
			int getGrade( void ) const;
			
			void increment( void );
			void decrement( void );
			void signForm( AForm& source );

			void executeForm(AForm const & form);
			
			static const int highestGrade = 1;
		    static const int lowestGrade = 150;
			
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

std::ostream & operator<<(std::ostream &o, Bureaucrat const &instance);

#include "AForm.hpp"

#endif		//==============BUREAUCRAT_HPP	

/* 
forward declarations are used in the header file to avoid circular dependencies,
 and the full inclusion of the corresponding header is done 
 in the implementation file. 
 This separation allows both classes to refer to each other 
 without causing compilation problems.
 The placement at the end of the header file is done to avoid any 
 circular dependencies that might exist between the two classes. 
 Circular dependencies can occur when two classes 
 include each other's headers directly, leading to a compilation issue.
*/