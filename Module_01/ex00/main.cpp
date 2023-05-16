/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:09:25 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 15:37:41 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie	first = Zombie("Zombrian");
	first.announce();
	Zombie*	zom_new = newZombie("NecroCodamer");
	zom_new->announce();
	randomChump("CirilPusPus");
	delete 	zom_new;
	return (0);
}
