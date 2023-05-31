/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:19:42 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 14:11:13 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)																	
{
	std::cout 	<< this->_name << " is born." << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << this->_name << " is dead" << std::endl;
}

void HumanA::attack() const
{
	std::cout 	<< this->_name << " attacks with their " 
				<< this->_weapon.getType() << std::endl;
}
