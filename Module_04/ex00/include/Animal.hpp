/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:54:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 12:19:24 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

class Animal
{
	protected:
			std::string _animalType;
	public:
			Animal( void );
			Animal(const Animal &source);
			virtual ~Animal( void );
			Animal & operator = (const Animal &source);

			const std::string& getType( void ) const;
			void setType(std::string type);
			
			virtual void makeSound( void ) const;
};

#endif		//==============ANIMAL_HPP	

/*
virtual function resolution only works when a virtual member function 
is called through a pointer or reference to a class type object. 
This works because the compiler can differentiate the type of the pointer 
or reference from the type of the object being pointed to or referenced. 
*/