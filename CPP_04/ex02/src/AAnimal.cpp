/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 16:31:30 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _animalType ("Abstract Animal")		
{
	std::cout 	<< YELLOW "Abstract animal default constructor" << std::endl;
}

AAnimal::AAnimal(std::string type ) : _animalType (type)		
{
	std::cout 	<< YELLOW "Abstract Animal " RESET " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &source) : _animalType (source._animalType)
{
	*this = source;
}

AAnimal::~AAnimal()
{
	std::cout 	<< DMGNT "Abstract Animal" RESET " destructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal &source)
{
	if (this == &source)
		return *this;

	this->_animalType = source._animalType;
	return *this;
}

const std::string& AAnimal::getType( void ) const
{
	return _animalType;
}
