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

WrongCat::WrongCat(void) : WrongAnimal()
{
	setType("Wrong Cat");
	std::cout 	<< RED "Wrong Cat constructor called " << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal()
{
	*this = source;
}

WrongCat::~WrongCat()
{
	std::cout 	<< DMGNT "Wrong Cat distructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat &source)
{
	if (this != &source) 
	{
		setType(source.getType());
	}
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout 	<< RED "The Wrong Cat roars"  RESET << std::endl;
}