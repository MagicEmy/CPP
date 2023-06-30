/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 12:33:38 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	setType("Cat");	
	std::cout 	<< ORANGE "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &source) : Animal()
{
	*this = source;
}

Cat::~Cat()
{
	std::cout 	<< DMGNT "Cat distructor called " << RESET << std::endl;
}

Cat& Cat::operator = (const Cat &source)
{
	if (this != &source) 
	{
		setType(source.getType());
	}
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout 	<< ORANGE "The cat meows"  RESET << std::endl;
}