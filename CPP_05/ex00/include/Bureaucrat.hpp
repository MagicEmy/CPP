/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:55:51 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/20 17:18:46 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>

class Bureaucrat
{
	private:
			const std::string _name;
			int	_grade;
	public:
			Bureaucrat( void );
			Bureaucrat( std::string name, int grade );
			Bureaucrat(const Bureaucrat &source);
			~Bureaucrat( void );
			Bureaucrat& operator = (const Bureaucrat &source);
			
			const std::string& getName() const;
			int getGrade( void ) const;
			
			void increment( void );
			void decrement( void );
			
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

std::ostream & operator<<(std::ostream &stream, Bureaucrat const &src);

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
