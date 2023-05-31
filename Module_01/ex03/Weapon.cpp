/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:04:39 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 13:43:50 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type) : _type (type) 
{
	std::cout << "New weapon created. Type: " << type << std::endl;
}

Weapon::~Weapon( void ) {}


std::string const & Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType(std::string	type)
{
	this->_type = type;
}
