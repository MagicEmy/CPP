/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:19:42 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:14:39 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)																	
{
	std::cout 	<< GREEN << this->_name << " is born." RESET
				<< std::endl;
}

HumanA::~HumanA( void )
{
	std::cout 	<< ORANGE << this->_name << " is dead" RESET 
				<< std::endl;
}

void HumanA::attack() const
{
	std::cout 	<< RED << this->_name << " attacks with their " 
				<< this->_weapon.getType() << RESET << std::endl;
}
