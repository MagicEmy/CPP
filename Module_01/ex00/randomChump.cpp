/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:29:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 15:33:49 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name )
{
	Zombie*	zom_Chump = new Zombie(name);
	zom_Chump->announce();
	delete zom_Chump;
}