/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 11:09:45 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(void) : _AMateriaType (" ")		
{
	std::cout << "Abstract materia " YELLOW "default constructor called." RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _AMateriaType (type)		
{
	std::cout << "Abstract materia " YELLOW "constructor called" RESET << std::endl;
}

AMateria::AMateria(const AMateria &source)
{
	*this = source;
}

AMateria::~AMateria()
{
	std::cout 	<< "Abstract materia  " DMGNT "destructor called " RESET << std::endl;
}

AMateria& AMateria::operator = (const AMateria &source)
{
	if (this == &source)
		return *this;
	_AMateriaType = source._AMateriaType;
	return *this;
}

const std::string& AMateria::getType( void ) const
{
	return _AMateriaType;
}

void AMateria::use(ICharacter& target)
{
	std::cout << " * spell on " << target.getName() << std::endl;
	
}