/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:00:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/06 13:42:25 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
	private:
			// //Name, which is passed as parameter to a constructor
			// std::string 	_Name;
			// //represent the health of the ScavTrap
			// unsigned int	_HitPoints;
			// unsigned int	_EnergyPoints;
			// unsigned int	_AttackDamage;
			
	public:

			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &source);
			~ScavTrap();
			ScavTrap & operator = (const ScavTrap &source);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			
			int getHitPoints( void ) const;
			int getEnergyPoints( void ) const;
			int getAttackDamage( void ) const;
			void setHitPoints( unsigned int const points);
			void setEnergyPoints( unsigned int const energy);
			void setAttackDamage( unsigned int const damage);

			void guardGate( void );
};

#endif
