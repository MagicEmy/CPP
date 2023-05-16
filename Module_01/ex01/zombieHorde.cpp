/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:04:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 18:33:34 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* Horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		Horde[i].setName(name);
	return Horde;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}