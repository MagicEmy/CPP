/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 10:32:46 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main (void)
{
    ClapTrap clapTrap("Clappy");
	ScavTrap scavTrap("Scavbot");

	std::cout << "\n";
    clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    // clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
	clapTrap.printStats();
    clapTrap.beRepaired(3);
    clapTrap.beRepaired(300);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(5);
    clapTrap.attack("Enemy");
	clapTrap.printStats();

	std::cout << "\n";
	scavTrap.attack("Enemy");
    scavTrap.takeDamage(5);
	scavTrap.printStats();
    scavTrap.beRepaired(300);
	scavTrap.printStats();
    scavTrap.attack("Enemy");
    scavTrap.attack("Enemy");
	scavTrap.printStats();
    scavTrap.beRepaired(3);
    scavTrap.takeDamage(5);
    scavTrap.guardGate();
    scavTrap.attack("Enemy");
	std::cout << "\n";

    return 0;
}
