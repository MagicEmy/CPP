/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:54:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 16:31:20 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSANIMAL_HPP
#define ABSANIMAL_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

class AbsAnimal
{
	protected:
			std::string _AbsAnimalType;
	public:
			AbsAnimal( void );
			AbsAnimal(const AbsAnimal &source);
			virtual ~AbsAnimal( void );
			AbsAnimal & operator = (const AbsAnimal &source);

			const std::string& getType( void ) const;
			void setType(std::string type);
			
			virtual void makeSound( void ) const = 0; // pure virtual function
			//Animal is now an abstract base class, and can not be instantiated.
};

#endif		//==============ANIMAL_HPP	

/*
virtual function resolution only works when a virtual member function 
is called through a pointer or reference to a class type object. 
This works because the compiler can differentiate the type of the pointer 
or reference from the type of the object being pointed to or referenced. 
*/