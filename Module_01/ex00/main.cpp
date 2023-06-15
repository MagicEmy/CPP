/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:09:25 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/14 10:42:05 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie	first = Zombie("Zombrian");
	first.announce();
	
	Zombie*	new_zom = newZombie("NecroCodamer");
	if (new_zom == nullptr)
		return 1;
	new_zom->announce();
	
	randomChump("CirilPusPus");
	
	delete 	new_zom;
	
	return (0);
}
