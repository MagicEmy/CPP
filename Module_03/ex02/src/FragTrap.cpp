/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:42:36 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 12:02:06 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)				
{
	std::cout << GREEN "FragTrap default constructor called." RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)					
{
	std::cout 	<< GREEN "FragTrap constructor called. Name: " << name 
				<< RESET << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	*this = source;
}

FragTrap::~FragTrap()
{
	std::cout	<< DGREEN "FragTrap distructor called. Name: " << _Name 
				<< RESET << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &source)
{
	if (this == &source)
		return *this;
		
	setHitPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints() <= 0)
	{	std::cout << AZURE "FragTrap cannot attack, no hit points or energy points left"
				  RESET << std::endl;
	}
	else
	{
		setHitPoints(getHitPoints() - getAttackDamage());
		_EnergyPoints--;
		std::cout 	<< L_AZURE C_UNDL C_BOLD "[ ATTACK ]" RESET L_AZURE
					<< " FragTrap " << _Name << " attacks "
					<< target << " causing " << getAttackDamage() 
					<<  " points of damage!" RESET << std::endl;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout 	<< YELLOW "FragTrap " << _Name 
				<< " goes in happy-frenzy mode and screams " B_VIOLET
				<< "Give me a high five! ✋ 😄" RESET
				<< std::endl;
}
