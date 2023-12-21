/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:42:36 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 16:17:44 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()			
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
	std::cout 	<< GREEN "FragTrap constructor called. Name: " << name 
				<< RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	*this = source;
}

FragTrap::~FragTrap()
{
	std::cout	<< DORANGE "FragTrap destructor called. Name: " << _Name 
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
	std::cout 	<< YELLOW "FragTrap " << _Name 
				<< " goes in happy-frenzy mode and screams " B_VIOLET
				<< "Give me a high five! ✋ 😄" RESET
				<< std::endl;
}
