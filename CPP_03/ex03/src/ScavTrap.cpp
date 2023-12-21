/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:20:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 16:18:10 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()		
{
	_Name = " ";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_MaxHitPoints = 100;
	std::cout << BLUE "ScavTrap default constructor called." RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)		
{
	std::cout 	<< BLUE "ScavTrap constructor called. Name: " << this->_Name 
				<< RESET << std::endl;

	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_MaxHitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	*this = source;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< CYAN "ScavTrap destructor called. Name: " << this->_Name 
				<< RESET << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &source)
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

void ScavTrap::attack(const std::string& target)
{
	if (_HitPoints <= 0)
		std::cout 	<< _Name << " cannot attack, Scav has no hit points left" << std::endl;
	else if (_EnergyPoints <= 0)
		std::cout 	<< _Name << " cannot attack, Scav has no energy points left" << std::endl;
	else
	{
		if (_EnergyPoints >= 0)
			_EnergyPoints--;
		else
			_EnergyPoints = 0;
		std::cout 	<< RED "ScavTrap Attack!! - " RESET << _Name << " attacks " 
					<< target << " causing " RED << _AttackDamage 
					<<  " points of damage!" << RESET << std::endl;
	}
}


void ScavTrap::guardGate()
{
	std::cout 	<< GREEN "🔒 🚪ScavTrap is now in Gate keeper mode. 🔒 🚪" RESET
				<< std::endl;
}