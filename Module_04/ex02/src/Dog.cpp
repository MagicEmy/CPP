/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 10:35:01 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")	
{
	this->_brain = new Brain();
	std::cout 	<< "Dog constructor called" GREEN 
				" Dog brings a ball" << RESET << std::endl;
}

Dog::Dog(const Dog &source) : AAnimal(source._animalType)
{
	std::cout << AZURE << "Dog Copy Constructor called" << std::endl;
	this->_brain = new Brain();
	*this = source;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout 	<< "Dog destructor called " GREEN 
				<< "Dog fetches the ball" << RESET << std::endl;
}

Dog& Dog::operator = (const Dog &source)
{
	if (this == &source)
		return *this;
	
	this->_animalType = source._animalType;
	*(this->_brain) = *(source._brain);
	std::cout << BLUE << "Dog Copy Assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout 	<< GREEN "Woof"  RESET << std::endl;
}

const std::string& Dog::getIdea( int i ) const
{
	return (this->_brain->getIdea(i));
}

void Dog::setIdea(std::string newIdea, int i)
{
	this->_brain->setIdea(newIdea, i);
}
