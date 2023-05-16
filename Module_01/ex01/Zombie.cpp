/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:48:20 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 18:38:17 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int Zombie::_index = 1;

Zombie::Zombie() : indexName (_index)
{
	std::cout << "Zombie number " << indexName << " is now alivezzzz" <<std::endl;
	_index += 1;
	
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " number " << indexName << " died...again" << std::endl;
	_index -= 1;
}

