/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 11:29:06 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria()	
{
	std::cout 	<< GREEN "Ice constructor called " << RESET << std::endl;
}

Ice::Ice(const Ice &source) : AMateria()
{
	*this = source;
}

Ice::~Ice()
{
	std::cout 	<< DMGNT "Ice distructor called " << RESET << std::endl;
}

Ice& Ice::operator = (const Ice &source)
{
	if (this != &source) 
	{
		// setType(source.getType());
	}
	return *this;
}
