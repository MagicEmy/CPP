/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/20 11:27:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat")
{
	std::cout 	<< DRED "Wrong Cat " << RESET "constructor called " << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source._wrongAnimalType)
{
	*this = source;
}

WrongCat::~WrongCat()
{
	std::cout 	<< DRED "Wrong Cat " << RESET "destructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat &source)
{
	if (this == &source)
		return *this;
	
	this->_wrongAnimalType = source._wrongAnimalType;
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout 	<< RED "The Wrong Cat roars"  RESET << std::endl;
}