/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:04:39 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:16:57 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type (type) 
{
	std::cout 	<< GREEN "New weapon created. Type: " << type 
				<< RESET << std::endl;
}

Weapon::~Weapon( void ) 
{
	std::cout 	<< ORANGE "Weapon Type: " << _type << " destroyed"
				RESET << std::endl;
}

std::string const & Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType(std::string	type)
{
	this->_type = type;
}
