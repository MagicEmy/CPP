/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 12:00:58 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("Ice")	
{
	std::cout 	<< GREEN "Ice constructor called " << RESET << std::endl;
}

Ice::Ice(const Ice &source) : AMateria(source._AMateriaType)
{
	*this = source;
}

Ice::~Ice()
{
	std::cout 	<< DMGNT "Ice destructor called " << RESET << std::endl;
}

Ice& Ice::operator = (const Ice &source)
{
	if (this == &source)
		return *this;

	this->_AMateriaType = source._AMateriaType;
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << " shoots an ice bolt at " << target.getName() <<" *$ " << std::endl;

}