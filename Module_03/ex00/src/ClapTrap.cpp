/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:41:26 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 16:52:25 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name (""), _HitPoints (10), _EnergyPoints (10), 
							_AttackDamage (0)	
{
	std::cout << BLUE "default constructor called" RESET << std::endl;
}


ClapTrap::ClapTrap(std::string name) : _Name (name), _HitPoints (10), 
										_EnergyPoints (10), _AttackDamage (0)						
{
	std::cout 	<< BLUE "constructor called. Name: " 
				<< name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
}

ClapTrap::~ClapTrap()
{
	std::cout 	<< CYAN "distructor called. Name: " << _Name 
				<< RESET << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &source)
{
	if (this == &source)
		return *this;
		
	setHitPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	return *this;
}

//When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
//Attacking costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout 	<< YELLOW << _Name 
					<< " cannot attack, no hit points or energy points left"
					<< " hit points = " << getHitPoints() << RESET << std::endl;
	}
	else
	{
		_EnergyPoints--;
		std::cout 	<< RED << _Name << " attacks"
					<< target << " causing " << getAttackDamage() 
					<<  " points of damage!" << "\tHit points = " << getHitPoints()
					<< "\tEnergy Points = " << getEnergyPoints() << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints >= 0)
	{
		setHitPoints(_HitPoints -= amount);
		std::cout	<< ORANGE << _Name << " takes "
					<< amount << " points of damage!" 
					<< "\t\tHit points = " << getHitPoints()
					<< "\tEnergy Points = " << getEnergyPoints() 
					<< RESET << std::endl;
	}
	else
	{
		std::cout	<< DORANGE << _Name << " is already destroyed. \
						It cannot take any more damage" 
					<< "\t\tHit points = " << getHitPoints()
					<< "\tEnergy Points = " << getEnergyPoints() 
					<< RESET << std::endl;	
	}
}

//When ClapTrap repairs itself, it gets <amount> hit points back.
//Repairing costs 1 energy point. 
//ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout 	<< DMGNT << _Name << " cannot be repaired "
					<< "no hit points or energy points left" << std::endl;
	}
	else
	{
		_HitPoints += amount;
		_EnergyPoints--;
		std::cout 	<< MGNT << _Name << " gets "
					<< amount << " hit points back!"
					<< RESET << std::endl;
	}
}

const std::string& ClapTrap::getName( void ) const
{
	return this->_Name;
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