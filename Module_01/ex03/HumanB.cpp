/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:29:04 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 13:44:20 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name (name), _weapon (nullptr) 
{
	std::cout << this->_name << " is born" << std::endl;
}

HumanB::~HumanB( void )
{
	std::cout << this->_name << " is dead" << std::endl;
}

void HumanB::attack() const
{
	if (_weapon == nullptr )
		std::cout << this->_name << " attacks with their bony hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " 
				  << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_weapon = &Weapon;
}

/*

void HumanB::attack() const {
	if (weapon != nullptr) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << name << " has no weapon to attack with!" << std::endl;
	}
}
*/