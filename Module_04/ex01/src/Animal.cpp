/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 12:30:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _animalType ("Random Animal")		
{
	std::cout 	<< YELLOW "Animal constructor called. Type: " 
				<< getType() << RESET << std::endl;
}

Animal::Animal(const Animal &source)
{
	*this = source;
}

Animal::~Animal()
{
	std::cout 	<< DMGNT "Animal distructor called. Type: " 	
				<< getType() << RESET << std::endl;
}

Animal& Animal::operator = (const Animal &source)
{
	if (this != &source) 
	{
		setType(source.getType());
	}
	return *this;
}

const std::string& Animal::getType(void) const
{
	return _animalType;
}

void Animal::setType(std::string type)
{
	this->_animalType = type;
}

void Animal::makeSound( void ) const
{
	std::cout 	<< YELLOW "A " << getType() 
				<< " makes a random sound"  RESET << std::endl;
}