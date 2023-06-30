/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 11:20:36 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(void) : _AMateriaType (" ")		
{
	std::cout 	<< YELLOW "Abstract materia default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : _AMateriaType (type)		
{
	std::cout 	<< YELLOW "Abstract materia constructor called. Type: " 
				<< getType() << RESET << std::endl;
}

AMateria::AMateria(const AMateria &source)
{
	*this = source;
}

AMateria::~AMateria()
{
	std::cout 	<< DMGNT "Abstract materia distructor called. Type: " 	
				<< getType() << RESET << std::endl;
}

AMateria& AMateria::operator = (const AMateria &source)
{
	// if (this != &source) 
	// {
	// 	setType(source.getType());
	// }
	return *this;
}

const std::string& AMateria::getType( void ) const
{
	return _AMateriaType;
}

// void AMateria::setType(std::string type)
// {
// 	this->_AMateriaType = type;
// }
