/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:20:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/16 16:55:48 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)				
{
	std::cout << BLUE "DiamondTrap default constructor called." RESET << std::endl;
}

/*ClapTrap::name (parameter of the constructor + "_clap_name" suffix)*/
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _Name(name)
{
	std::cout 	<< BLUE "DiamondTrap constructor called. Name: " << name 
				<< RESET << std::endl;
	setHitPoints(100);						//Hit points (FragTrap)
	setEnergyPoints(50);					//Energy points (ScavTrap)
	setAttackDamage(30);					//Attack damage (FragTrap)
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) : ClapTrap(source)
{
	*this = source;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< CYAN "DiamondTrap distructor called. Name: " << _Name 
				<< RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &source)
{
	if (this == &source)
		return *this;
		
	setHitPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	setEnergyPoints(source.getHitPoints());
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout 	<< YELLOW "[ GREETINGS ] My name is " << DiamondTrap::_Name 
				<< " and ClapTrap name is " << ClapTrap::_Name 
				<< RESET << std::endl;
}
/*
This member function will display both its name and its ClapTrap name.*/
