/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 10:32:09 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main (void)
{
    ClapTrap clapTrap("ClappyBot");
	ScavTrap scavTrap("ChatGPT");
	FragTrap fragtrap("Happy Dude");

	std::cout << "\n";
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(1);
    clapTrap.beRepaired(300);
    clapTrap.attack("Enemy");

	std::cout << "\n";
	scavTrap.attack("Clappy");
    scavTrap.takeDamage(25);
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(1000);
    scavTrap.guardGate();
    scavTrap.attack("Happy Dude");
    scavTrap.takeDamage(1);
    scavTrap.attack("Happy Dude");

	std::cout << "\n";
	fragtrap.attack("ChatGPT");
    fragtrap.highFivesGuys();
	fragtrap.attack("ChatGPT");
    fragtrap.takeDamage(5);
	fragtrap.attack("ChatGPT");
	fragtrap.attack("ChatGPT");
    fragtrap.beRepaired(300);
    fragtrap.attack("ChatGPT");
	
	std::cout << "\n";
    return 0;
}
