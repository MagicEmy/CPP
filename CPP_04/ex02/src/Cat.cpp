/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 10:34:37 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	this->_brain = new Brain;
	std::cout 	<< "Cat constructor called " ORANGE "Cat stares at you" << RESET << std::endl;
}

Cat::Cat(const Cat &source) : AAnimal(source._animalType)
{
	this->_brain = new Brain();
	*this = source;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout 	<< "Cat destructor is called. " ORANGE "Cat purrs away"
				<< RESET << std::endl;
}

Cat& Cat::operator = (const Cat &source)
{
	if (this == &source)
		return *this;
	
	this->_animalType = source._animalType;
	*(this->_brain) = *(source._brain);
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout 	<< ORANGE "Meow"  RESET << std::endl;
}

const std::string& Cat::getIdea( int i ) const
{
	return (this->_brain->getIdea(i));
}

void Cat::setIdea(std::string	newIdea, int i)
{
	this->_brain->setIdea(newIdea, i);
}