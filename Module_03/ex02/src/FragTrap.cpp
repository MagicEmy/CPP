/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:42:36 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 16:16:36 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)				
{
	_Name = " ";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	_MaxHitPoints = 100;
	std::cout << GREEN "FragTrap default constructor called." RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)					
{
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	_MaxHitPoints = 100;
	std::cout 	<< GREEN "FragTrap constructor called. Name: " << this->_Name 
				<< RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	*this = source;
}

FragTrap::~FragTrap()
{
	std::cout	<< GREEN "FragTrap destructor called. Name: " << this->_Name
				<< RESET << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &source)
{
	if (this == &source)
		return *this;
		
	_Name = source._Name;
	_HitPoints = source._HitPoints;
	_EnergyPoints = source._EnergyPoints;
	_AttackDamage = source._AttackDamage;
	_MaxHitPoints = source._MaxHitPoints;
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout 	<< YELLOW "FragTrap " <<  this->_Name
				<< " goes in happy-frenzy mode and screams " B_VIOLET
				<< "Give me a high five! ✋ 😄" RESET
				<< std::endl;
}
