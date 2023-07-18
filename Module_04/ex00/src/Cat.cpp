/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 10:16:05 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout 	<< "Cat constructor called " ORANGE "Cat stares at you" << RESET << std::endl;
}

Cat::Cat(const Cat &source) : Animal(source._animalType)
{
	*this = source;
}

Cat::~Cat()
{
	std::cout 	<< "Cat destructor is called " ORANGE 
				"Cat purrs away" 
				<< RESET << std::endl;
}

Cat& Cat::operator = (const Cat &source)
{
	if (this == &source)
		return *this;
	
	this->_animalType = source._animalType;
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout 	<< ORANGE "Meow"  RESET << std::endl;
}