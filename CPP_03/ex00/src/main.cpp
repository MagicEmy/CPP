/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/04 10:11:40 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main (void)
{
	{
    ClapTrap clapTrap("Clappy");
	
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(30);
	clapTrap.printStats();
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
	clapTrap.printStats();
	}
	{
	std::cout << "\n";
	ClapTrap clapTrap("Trappy");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
	clapTrap.printStats();
    clapTrap.beRepaired(30);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(5);
	clapTrap.beRepaired(1);
	clapTrap.printStats();
    clapTrap.attack("Enemy");
	}

    return 0;
}


