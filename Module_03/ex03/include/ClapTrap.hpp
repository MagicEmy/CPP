/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:00:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/03 13:23:44 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define RED		"\x1b[38;2;255;0;0m"
#define DRED	"\x1b[38;2;128;0;0m"
#define GREEN	"\x1b[38;2;0;255;0m"
#define ORANGE	"\x1b[38;2;255;128;0m"
#define DORANGE	"\x1b[38;2;128;64;0m"
#define YELLOW	"\x1b[38;2;255;255;0m"
#define CYAN	"\x1b[38;2;0;255;255m"
#define BLUE	"\033[34m"
#define MGNT	"\x1b[38;2;255;0;255m"
#define DMGNT	"\x1b[38;2;128;0;128m"
#define B_VIOLET	"\x1b[48;2;128;0;255m"
#define RESET	"\033[0m"

class ClapTrap
{
	protected:
			std::string 	_Name;
			unsigned int	_HitPoints;
			unsigned int	_EnergyPoints;
			unsigned int	_AttackDamage;
			unsigned int	_MaxHitPoints;

			void setHitPoints( unsigned int const points);
			void setEnergyPoints( unsigned int const energy);
			void setAttackDamage( unsigned int const damage);
			
	public:
			ClapTrap( void );
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &source);
			~ClapTrap( void );
			ClapTrap & operator = (const ClapTrap &source);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			
			const std::string& getName( void ) const;
			int getHitPoints( void ) const;
			int getEnergyPoints( void ) const;
			int getAttackDamage( void ) const;
			void printStats( void );
};

#endif
