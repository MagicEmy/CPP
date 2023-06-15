/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:20:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/12 18:34:24 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)				
{
	std::cout << BLUE "ScavTrap default constructor called." RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)					
{
	std::cout 	<< BLUE "ScavTrap constructor called. Name: " << name 
				<< RESET << std::endl;
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
	std::cout	<< CYAN "ScavTrap distructor called. Name: " << _Name 
				<< RESET << std::endl;
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

void ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout << DMGNT "ScavTrap cannot attack, no hit points or energy points left"
				  RESET << std::endl;
	}
	else
	{
		setHitPoints(getHitPoints() - getAttackDamage());
		_EnergyPoints--;
		std::cout	<< DMGNT C_UNDL C_BOLD "[ ATTACK ]" RESET DMGNT 	
					<< " ScavTrap " << _Name << " attacks "
					<< target << " causing " << getAttackDamage() 
					<<  " points of damage!" RESET << std::endl;
	}
}


void ScavTrap::guardGate()
{
	std::cout 	<< YELLOW "🔒 🚪ScavTrap is now in Gate keeper mode. 🔒 🚪" RESET
				<< std::endl;
}