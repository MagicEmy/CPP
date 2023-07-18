/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 09:46:53 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _animalType ("Animal")		
{
	std::cout 	<< DMGNT "Animal" RESET " default constructor called " << std::endl;

}

Animal::Animal(std::string type ) : _animalType (type)		
{
	std::cout 	<< "Animal constructor called for " MGNT << _animalType
				<< RESET << std::endl;
}

Animal::Animal(const Animal &source) : _animalType (source._animalType)
{
	*this = source;
}

Animal::~Animal()
{
	std::cout 	<< DYELLOW "Animal destructor called" RESET << std::endl;
}

Animal& Animal::operator = (const Animal &source)
{
	if (this == &source)
		return *this;
	
	this->_animalType = source._animalType;
	return *this;
}

const std::string& Animal::getType( void ) const
{
	return _animalType;
}

void Animal::makeSound( void ) const
{
	std::cout 	<< YELLOW  << getType() 
				<<  RESET " makes a random sound" << std::endl;
}