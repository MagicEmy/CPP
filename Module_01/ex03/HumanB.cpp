/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:29:04 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/14 15:46:39 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name (name), _weapon (nullptr) 
{
	std::cout << GREEN << this->_name << " is born" << RESET << std::endl;
}

HumanB::~HumanB( void )
{
	std::cout << ORANGE << this->_name << " is dead" << RESET << std::endl;
}

void HumanB::attack() const
{
	if (_weapon == nullptr )
		std::cout 	<< YELLOW << this->_name << " attacks without a weapon but with verbal and emotional abuse." 
					RESET << std::endl;
	else
		std::cout << RED << this->_name << " attacks with their " 
				  << this->_weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_weapon = &Weapon;
}
