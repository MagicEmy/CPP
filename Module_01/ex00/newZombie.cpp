/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:27:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/14 10:25:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie*	new_zombie = new Zombie(name);
	if (!new_zombie)
	{
		std::cout << "Allocation failed!" << std::endl;
		return (nullptr);
	}
	return new_zombie;
}
