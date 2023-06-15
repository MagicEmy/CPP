/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/12 18:30:48 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main (void)
{
    ClapTrap clapTrap("Clappy");
	ScavTrap scavTrap("ChatGPT");
	FragTrap fragtrap("Happy Dude");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(1);
    clapTrap.beRepaired(3);
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");

	scavTrap.attack("Clappy");
    scavTrap.takeDamage(25);
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    scavTrap.attack("Happy Dude");
    scavTrap.takeDamage(1);
    scavTrap.attack("Happy Dude");

	fragtrap.attack("ChatGPT");
    fragtrap.highFivesGuys();
	fragtrap.attack("ChatGPT");
    fragtrap.takeDamage(5);
	fragtrap.attack("ChatGPT");
	fragtrap.attack("ChatGPT");
    fragtrap.beRepaired(3);
    fragtrap.attack("ChatGPT");
    fragtrap.attack("ChatGPT");
	
    return 0;
}
