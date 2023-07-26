/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:02:21 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/25 15:36:35 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"


class Intern
{
	private: 

	public:
			Intern( void );					
			~Intern( void );					
			Intern( const Intern& src );					
			Intern& operator = ( const Intern& src );
							
			AForm* makeForm(const std::string& formName, const std::string& target);
			
			class FormNotFound : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
};

#endif