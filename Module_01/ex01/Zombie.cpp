/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:48:20 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 18:54:13 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::_index = 1;

Zombie::Zombie() : indexName (_index)
{
	std::cout 	<< GREEN "Zombie number " << indexName << " is now alivezzzz" 
				RESET <<std::endl;
	_index += 1;
	
}

Zombie::~Zombie()
{
	std::cout 	<< ORANGE << _name << " number " << indexName << " died...again" 
				RESET << std::endl;
	_index -= 1;
}


void	Zombie::announce( void )
{
	std::cout 	<< YELLOW << this->_name << ": BraiiiiiiinnnzzzZ..." RESET
				<< std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}