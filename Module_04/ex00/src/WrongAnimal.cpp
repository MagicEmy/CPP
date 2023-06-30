/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/19 19:39:33 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _wrongAnimalType ("Random weird Animal")		
{
	std::cout 	<< BLUE "Wrong Animal constructor called. Type: " 
				<< getType() << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
	*this = source;
}

WrongAnimal::~WrongAnimal()
{
	std::cout 	<< DMGNT "Wrong Animal distructor called. Type: " 	
				<< getType() << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &source)
{
	if (this != &source) 
	{
		setType(source.getType());
	}
	return *this;
}

const std::string& WrongAnimal::getType( void ) const
{
	return _wrongAnimalType;
}

void WrongAnimal::setType(std::string type)
{
	this->_wrongAnimalType = type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout 	<< BLUE "Overload failed. A " << getType() 
				<< " sings <In the jungle the mighty jungle a wrong Animal sleeps tonight>"  
				RESET << std::endl;
}