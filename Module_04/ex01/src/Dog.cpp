/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 12:22:15 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()	
{
	setType("Dog");
	this->_brain = new Brain();
	//try and catch
	std::cout 	<< GREEN "Dog constructor called " << RESET << std::endl;
}

Dog::Dog(const Dog &source) : Animal()
{
	// this->_brain = new Brain(); ??
	this->_brain = new Brain(*(source._brain));
	// *this = source;
}

Dog::~Dog()
{
	delete this->_brain;
	//try and catch
	std::cout 	<< DMGNT "Dog distructor called" << RESET << std::endl;
}

Dog& Dog::operator = (const Dog &source)
{
	if (this == &source)
		return *this;
	
	setType(source.getType());
	
	delete this->_brain;
	this->_brain = new Brain(*(source._brain));
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout 	<< GREEN "The dog barks to the moon"  RESET << std::endl;
}

/*
In the context of the given subject, a shallow copy refers to creating a new 
object that is a bit-wise copy of the original object. 
This means that if an object contains pointers to dynamically allocated memory, 
a shallow copy would simply copy the memory addresses without 
creating new copies of the dynamically allocated memory. 
As a result, both the original object and the copied object 
would be pointing to the same memory locations, 
which can lead to issues when one object is modified or deallocated.

On the other hand, a deep copy involves creating a new object 
and duplicating the dynamically allocated memory as well. 
So, if an object has a pointer to some memory that was allocated using new, 
a deep copy would allocate new memory and copy the contents 
from the original memory location to the newly allocated memory. 
This way, the original object and the copied object would have their own separate memory.

In the given subject, it is stated that a copy of a Dog or a Cat 
mustn't be shallow. This means that when you create a copy 
of a Dog or a Cat object, you should ensure that the dynamically 
allocated memory (the Brain object) is also duplicated. 
In other words, each copy of a Dog or a Cat should have its own 
separate Brain object, rather than sharing the same Brain object with the original.

To ensure that the copies are deep copies, 
you need to implement a proper copy constructor and 
assignment operator for the Dog and Cat classes. 
These member functions should allocate new memory 
for the Brain object and copy the contents of the original Brain object 
to the newly allocated memory. 
This way, each object will have its own independent copy of the Brain.

After implementing the deep copy mechanism, 
ou should test it to ensure that it works correctly. 
You can do this by creating copies of Dog and Cat objects and modifying 
the ideas array of the original and copied objects separately. 
If the deep copy is successful, modifying the ideas array of one object 
should not affect the other object, as they will have separate copies of the Brain object.
*/