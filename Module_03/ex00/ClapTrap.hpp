/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:00:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/06 14:33:15 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ClapTrap
{
	private:
			//Name, which is passed as parameter to a constructor
			std::string 	_Name;
			//represent the health of the ClapTrap
			unsigned int	_HitPoints;
			unsigned int	_EnergyPoints;
			unsigned int	_AttackDamage;
			
	public:

			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &source);
			~ClapTrap();
			ClapTrap & operator = (const ClapTrap &source);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			
			int getHitPoints( void ) const;
			int getEnergyPoints( void ) const;
			int getAttackDamage( void ) const;
			void setHitPoints( unsigned int const points);
			void setEnergyPoints( unsigned int const energy);
			void setAttackDamage( unsigned int const damage);
};

#endif
