/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:41:26 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/06 13:46:09 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _Name (name), _HitPoints (10), 
										_EnergyPoints (10), _AttackDamage (0)						
{
	std::cout << "ClapTrap constructor called. Name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap distructor called. Name: " << _Name << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &source)
{
	if (this != &source) 
	{
		setHitPoints(source.getHitPoints());
		setEnergyPoints(source.getHitPoints());
		setEnergyPoints(source.getHitPoints());
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
		std::cout 	<< "ClapTrap " << _Name << " attacks"
					<< target << " causing " << getAttackDamage() 
					<<  " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints >= 0)
	{
		std::cout	<< "ClapTrap " << _Name << " takes "
					<< amount << " points of damage!" 
					<< std::endl;
		setHitPoints(_HitPoints -= amount);
	}
	else
	{
		std::cout	<< "ClapTrap " << _Name << " is already destroyed. \
						It cannot take any more damage" << std::endl;		
	}
}

//When ClapTrap repairs itself, it gets <amount> hit points back.
//Repairing costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout 	<< "ClapTrap cannot be repaired "
					<< "no hit points or energy points left" << std::endl;
	}
	else
	{
		_HitPoints += amount;
		std::cout 	<< "ClapTrap " << _Name << " gets "
					<< amount << " hit points back!" << std::endl;
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