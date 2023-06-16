/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:04:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/16 15:16:23 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string randomName()
{
	std::string names [] = { 
		"Zombrian", 
		"NecroCodamer", 
		"CirilPusPus",
		"Zomzilla",
		"Undeadpool",
		"Undaddycool",
		"Zombeer",
		"Zombody",
		"ZumbaZombie",
	};
	int arr_size = sizeof (names)/sizeof (names [0]);
	int randomIndex = std::rand() % arr_size;
	return (names [randomIndex]);
}


Zombie* zombieHorde( int N, std::string name )
{
	std::cout 	<< "test " << N << " \n";
	if (N <= 0)
    {
        std::cout 	<< RED "Invalid size for zombie horde. Creating an empty horde." 
					RESET << std::endl;
        return nullptr;
    }
	Zombie* Horde = new Zombie[N];
	if (!Horde)
	{
		std::cout << "Allocation failed!" << std::endl;
		return (nullptr);
	}
	for (int i = 0; i < N; ++i)
		Horde[i].setName(name + " " + randomName());
	return Horde;
}
