/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 10:35:39 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")	
{
	std::cout 	<< "Dog constructor called" GREEN 
				" Dog brings a ball" << RESET << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source._animalType)
{
	*this = source;
}

Dog::~Dog()
{
	std::cout 	<< "Dog destructor called, " GREEN 
				<< "Dog fetches the ball" << RESET << std::endl;
}

Dog& Dog::operator = (const Dog &source)
{
	if (this == &source)
		return *this;
		
	this->_animalType = source._animalType;
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout 	<< GREEN "Woof"  RESET << std::endl;
}