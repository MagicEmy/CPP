/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:20:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/06 14:33:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)					
{
	std::cout << "ScavTrap constructor called. Name: " << name << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	*this = source;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap distructor called. Name: " << _Name << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &source)
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
//ScavTrap can’t do anything if it has no hit points or energy points left.
void ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout << "ScavTrap cannot attack, no hit points or energy points left"
				  << std::endl;
	}
	else
	{
		setHitPoints(getHitPoints() - getAttackDamage());
		_EnergyPoints--;
		std::cout 	<< "ScavTrap " << _Name << " attacks"
					<< target << " causing " << getAttackDamage() 
					<<  " points of damage!" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints >= 0)
	{
		std::cout	<< "ScavTrap " << _Name << " takes "
					<< amount << " points of damage!" 
					<< std::endl;
		setHitPoints(_HitPoints -= amount);
	}
	else
	{
		std::cout	<< "ScavTrap " << _Name << " is already destroyed. \
						It cannot take any more damage" << std::endl;		
	}
}

//When ScavTrap repairs itself, it gets <amount> hit points back.
//Repairing costs 1 energy point. 
//ScavTrap can’t do anything if it has no hit points or energy points left.
void ScavTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout 	<< "ScavTrap cannot be repaired "
					<< "no hit points or energy points left" << std::endl;
	}
	else
	{
		_HitPoints += amount;
		std::cout 	<< "ScavTrap " << _Name << " gets "
					<< amount << " hit points back!" << std::endl;
	}
}

int ScavTrap::getHitPoints( void ) const
{
	return this->_HitPoints;
}

int ScavTrap::getEnergyPoints( void ) const
{
	return this->_EnergyPoints;
}

int ScavTrap::getAttackDamage( void ) const
{
	return this->_AttackDamage;
}

void ScavTrap::setHitPoints( unsigned int const hitPoints)
{
	this->_HitPoints = hitPoints;
}

void ScavTrap::setEnergyPoints( unsigned int const energy)
{
	this->_EnergyPoints = energy;
}

void ScavTrap::setAttackDamage( unsigned int const damage)
{
	this->_AttackDamage = damage;
}

void ScavTrap::guardGate()
{
	std::cout 	<< "ScavTrap is now in Gate keeper mode." << std::endl;
}