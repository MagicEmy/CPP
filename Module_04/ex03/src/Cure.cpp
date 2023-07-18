/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 12:00:23 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{
	std::cout 	<< ORANGE "Cure constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &source) : AMateria(source._AMateriaType)
{
	*this = source;
}

Cure::~Cure()
{
	std::cout 	<< DMGNT "Cure destructor called " << RESET << std::endl;
}

Cure& Cure::operator = (const Cure &source)
{
	if (this == &source)
		return *this;

	this->_AMateriaType = source._AMateriaType;
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << " * heals " << target.getName() <<"'s wounds *" << std::endl;
	
}