/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 16:31:30 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal(void) : _AbsAnimalType ("Random Abstract Animal")		
{
	std::cout 	<< YELLOW "Abstract animal constructor called. Type: " 
				<< getType() << RESET << std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal &source)
{
	*this = source;
}

AbsAnimal::~AbsAnimal()
{
	std::cout 	<< DMGNT "Abstract Animal distructor called. Type: " 	
				<< getType() << RESET << std::endl;
}

AbsAnimal& AbsAnimal::operator = (const AbsAnimal &source)
{
	if (this != &source) 
	{
		setType(source.getType());
	}
	return *this;
}

const std::string& AbsAnimal::getType( void ) const
{
	return _AbsAnimalType;
}

void AbsAnimal::setType(std::string type)
{
	this->_AbsAnimalType = type;
}

void AbsAnimal::makeSound( void ) const
{
	std::cout 	<< YELLOW "A " << getType() 
				<< " makes a random sound"  RESET << std::endl;
}