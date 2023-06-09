/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:41:26 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/08 17:29:55 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)				
{
	std::cout << BLUE "ClapTrap default constructor called." RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name (name), _HitPoints (10), 
										_EnergyPoints (10), _AttackDamage (0)						
{
	std::cout << MGNT "ClapTrap constructor called. Name: " << name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
}

ClapTrap::~ClapTrap()
{
	std::cout << BLUE "ClapTrap distructor called. Name: " << _Name << RESET << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &source)
{
	if (this != &source) 
	{
		_HitPoints = source.getHitPoints();
		_EnergyPoints = source.getEnergyPoints();
		_AttackDamage = source.getAttackDamage();
	}
	return *this;
}

//When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
//Attacking costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout << "ClapTrap cannot attack, no hit points or energy points left"
				  << std::endl;
	}
	else
	{
		setHitPoints(getHitPoints() - getAttackDamage());
		_EnergyPoints--;
		std::cout 	<< RED "ClapTrap " << _Name << " attacks "
					<< target << " causing " << getAttackDamage() 
					<<  " points of damage!" RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints >= 0)
	{
		std::cout	<< ORANGE "ClapTrap " << _Name << " takes "
					<< amount << " points of damage!" RESET
					<< std::endl;
		setHitPoints(_HitPoints -= amount);
	}
	else
	{
		std::cout	<< DORANGE "ClapTrap " << _Name << " is already destroyed. \
						It cannot take any more damage" RESET << std::endl;		
	}
}

//When ClapTrap repairs itself, it gets <amount> hit points back.
//Repairing costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout 	<< YELLOW "ClapTrap cannot be repaired "
					<< "no hit points or energy points left" RESET << std::endl;
	}
	else
	{
		_HitPoints += amount;
		std::cout 	<< GREEN "ClapTrap " << _Name << " gets "
					<< amount << " hit points back!" RESET << std::endl;
	}
}

int ClapTrap::getHitPoints( void ) const
{
	return this->_HitPoints;
}

int ClapTrap::getEnergyPoints( void ) const
{
	return this->_EnergyPoints;
}

int ClapTrap::getAttackDamage( void ) const
{
	return this->_AttackDamage;
}

void ClapTrap::setHitPoints( unsigned int const hitPoints)
{
	this->_HitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints( unsigned int const energy)
{
	this->_EnergyPoints = energy;
}

void ClapTrap::setAttackDamage( unsigned int const damage)
{
	this->_AttackDamage = damage;
}