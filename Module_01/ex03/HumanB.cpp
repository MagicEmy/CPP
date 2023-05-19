/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:29:04 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/18 13:25:37 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name (name), _weapon (nullptr) {}

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