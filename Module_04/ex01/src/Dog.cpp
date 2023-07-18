/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 10:35:09 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")	
{
	this->_brain = new Brain();
	std::cout 	<< "Dog constructor called" GREEN 
				" Dog brings a ball" << RESET << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source._animalType)
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

/*
A deep copy involves creating a new object 
and duplicating the dynamically allocated memory as well. 
So, if an object has a pointer to some memory that was allocated using new, 
a deep copy would allocate new memory and copy the contents 
from the original memory location to the newly allocated memory. 
This way, the original object and the copied object would have their 
own separate memory.

a shallow copy would simply copy the memory addresses without 
creating new copies of the dynamically allocated memory. 
As a result, both the original object and the copied object 
would be pointing to the same memory locations, 
which can lead to issues when one object is modified or deallocated.

you need to implement a proper copy constructor and 
assignment operator for the Dog and Cat classes. 

this->_brain and source._brain are pointers to Brain objects.
*(this->_brain) and *(source._brain) dereference these pointers 
to access the actual Brain objects.
The Brain class has its own copy assignment operator that performs 
a deep copy of the _ideas array.
Therefore, *(this->_brain) = *(source._brain) invokes the copy assignment 
operator of the Brain class to copy the array of ideas 
from the source object's brain to the destination object's brain.
Finally, the copy assignment operator returns a reference to *this, 
allowing for chaining multiple assignments if needed.

In summary, the copy constructor for Dog creates a new Brain object and 
then assigns values from the source object using the copy assignment operator. 
The copy assignment operator performs a shallow copy of the base class data 
and a deep copy of the Brain object's data, ensuring that a copy of a Dog object 
results in a complete and independent replica.
*/