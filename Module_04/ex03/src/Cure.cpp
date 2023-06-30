/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 12:03:40 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria()
{
	std::cout 	<< ORANGE "Cure constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &source) : AMateria()
{
	*this = source;
}

Cure::~Cure()
{
	std::cout 	<< DMGNT "Cure distructor called " << RESET << std::endl;
}

Cure& Cure::operator = (const Cure &source)
{
	if (this != &source) 
	{
		// setType(source.getType());
	}
	return *this;
}

AMateria* clone()