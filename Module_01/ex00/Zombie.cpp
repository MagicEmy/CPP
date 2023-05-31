/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:22:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 13:37:53 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) 
{
	std::cout << "Zombie " << this->_name << " is aliveee" << std::endl;
}
			
Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is finally dead" << std::endl;
}
