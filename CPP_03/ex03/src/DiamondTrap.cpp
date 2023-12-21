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

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), _Name(" ")
{
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	_MaxHitPoints = FragTrap::_HitPoints;;
	std::cout << BLUE "DiamondTrap default constructor called." RESET << std::endl;
}

/*ClapTrap::name (parameter of the constructor + "_clap_name" suffix)*/
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), 
											 ScavTrap(ClapTrap::_Name), 
											 FragTrap(ClapTrap::_Name), 
											 _Name(name)
{
	std::cout 	<< BLUE "DiamondTrap constructor called. Name: " << _Name 
				<< RESET << std::endl;
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
	_MaxHitPoints = FragTrap::_HitPoints;;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) : ClapTrap(source), \
													ScavTrap(source), FragTrap(source),\
													_Name(source._Name){
	*this = source;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< CYAN "DiamondTrap destructor called. Name: " << _Name 
				<< RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &source)
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

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout 	<< YELLOW "[ GREETINGS ] My name is " << DiamondTrap::_Name 
				<< " and ClapTrap name is " << ClapTrap::_Name 
				<< RESET << std::endl;
}

/*

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    _name = other._name;
    return (*this);
}

}*/