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

WrongAnimal::WrongAnimal(void) : _wrongAnimalType ("Wrong Animal")		
{
	std::cout 	<< RED "Wrong Animal " << RESET "constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type ) : _wrongAnimalType (type)		
{
	std::cout 	<< "Animal constructor called. Type: " MGNT
				<< _wrongAnimalType << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source) : _wrongAnimalType(source._wrongAnimalType)
{
	*this = source;
}

WrongAnimal::~WrongAnimal()
{
	std::cout 	<< RED "Wrong Animal " << RESET "destructor called" RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &source)
{
	if (this == &source)
		return *this;
	
	this->_wrongAnimalType = source._wrongAnimalType;
	return *this;
}

const std::string& WrongAnimal::getType( void ) const
{
	return _wrongAnimalType;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout 	<< BLUE "Override failed. " RESET
				<< "WrongAnimal sound is a weird sound"  << std::endl;
}