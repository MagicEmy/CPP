/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 12:32:44 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()	
{
	setType("Dog");	
	std::cout 	<< GREEN "Dog constructor called " << RESET << std::endl;
}

Dog::Dog(const Dog &source) : Animal()
{
	*this = source;
}

Dog::~Dog()
{
	std::cout 	<< DMGNT "Dog distructor called " << RESET << std::endl;
}

Dog& Dog::operator = (const Dog &source)
{
	if (this != &source) 
	{
		setType(source.getType());
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout 	<< GREEN "The dog barks to the moon"  RESET << std::endl;
}