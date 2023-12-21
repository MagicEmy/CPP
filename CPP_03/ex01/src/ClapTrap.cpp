/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:24:47 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 16:14:22 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name (""), _HitPoints (10), _EnergyPoints (10), 
							_AttackDamage (0), _MaxHitPoints(10)
{
	std::cout << "default constructor called" << std::endl;

}


ClapTrap::ClapTrap(std::string name) : _Name (name), _HitPoints (10),
										_EnergyPoints (10), _AttackDamage (0),
										_MaxHitPoints(10)		
{
	std::cout 	<< "ClapTrap constructor called. Name: " DMGNT
				<< _Name<< RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
}

ClapTrap::~ClapTrap()
{
	std::cout 	<< "destructor called. Name: " CYAN << _Name 
				<< RESET << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &source)
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

//When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
//Attacking costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::attack(const std::string& target)
{
	if (_HitPoints <= 0)
		std::cout 	<< _Name << " cannot attack, no hit points left" << std::endl;
	else if (_EnergyPoints <= 0)
		std::cout 	<< _Name << " cannot attack, no energy points left" << std::endl;
	else
	{
		if (_EnergyPoints >= 0)
			_EnergyPoints--;
		else
			_EnergyPoints = 0;
		std::cout 	<< RED "Attack - " RESET << _Name << " attacks " 
					<< target << " causing " RED << _AttackDamage 
					<<  " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints > 0)
	{
		if (amount > _HitPoints)
			_HitPoints = 0;
		else
			_HitPoints -= amount;
		std::cout	<< ORANGE "Damage - " RESET << _Name << " takes " ORANGE
					<< amount << " points" RESET " of damage!" << std::endl;
	}
	else
		std::cout	<< _Name << DORANGE " is destroyed, " RESET
					<< "it cannot take any more damage" << std::endl;	
}

//When ClapTrap repairs itself, it gets <amount> hit points back.
//Repairing costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HitPoints <= 0)
		std::cout 	<< _Name << " cannot be repaired: no hit points left" << std::endl;
	else if (_EnergyPoints <= 0)
		std::cout 	<< _Name << " cannot be repaired: no energy points left" << std::endl;
	else
	{
		if (_EnergyPoints >= 0)
			_EnergyPoints--;
		else
			_EnergyPoints = 0;
		if ((_HitPoints + amount) > _MaxHitPoints)
		{
			std::cout 	<< MGNT "Repair - " << amount << RESET 
						<< " Max health score is " << _MaxHitPoints << " "
						<< _Name << " is now fully healed" RESET << std::endl;
			_HitPoints = _MaxHitPoints;
		}
		else
		{
			_HitPoints += amount;
			std::cout 	<< MGNT "Repair - " RESET << _Name << " gets " MGNT 
						<< amount << " hit points back!" << RESET << std::endl;
		}
	}
}


void ClapTrap::printStats( void )
{
	std::cout	<< "Hit points = " YELLOW << _HitPoints
				<< RESET "\tEnergy Points = " BLUE << _EnergyPoints 
				<< RESET << std::endl;
}