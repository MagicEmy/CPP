/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:20:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 12:01:49 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()		
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
	if (this == &source)
		return *this;
		
	setHitPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout 	<< YELLOW "ScavTrap is now in Gate keeper mode." RESET
				<< std::endl;
}