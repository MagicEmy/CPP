/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:00:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/08 17:32:32 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

// #define DMGNT	"\x1b[38;2;128;0;128m"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &source);
		~ScavTrap( void );
		ScavTrap & operator = (const ScavTrap &source);

		void guardGate( void );
		void attack(const std::string& target);
};

#endif
