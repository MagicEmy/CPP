/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 12:07:11 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main (void)
{
    ClapTrap clapTrap("Clappy");
	ScavTrap scavTrap("robot");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");

	scavTrap.attack("Enemy");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(3);
    scavTrap.guardGate();
    scavTrap.attack("Enemy");
    scavTrap.attack("Enemy");

    return 0;
}
