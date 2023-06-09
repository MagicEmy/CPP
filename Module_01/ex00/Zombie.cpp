/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:22:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 18:45:18 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) 
{
	std::cout 	<< GREEN "Zombie " << this->_name << " is aliveee" RESET
				<< std::endl;
}
			
Zombie::~Zombie()
{
	std::cout 	<< ORANGE "Zombie " << this->_name << " is finally dead" RESET
				<< std::endl;
}

void	Zombie::announce()
{
	std::cout 	<< YELLOW << this->_name << ": BraiiiiiiinnnzzzZ..." RESET
				<< std::endl;
}
