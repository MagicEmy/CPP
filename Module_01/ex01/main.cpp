/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:44 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 18:55:16 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testHorde(int size, std::string name)
{
	if (size <= 0)
    {
        std::cout 	<< RED "Invalid size for zombie horde. Creating an empty horde." 
					RESET << std::endl;
        return ;
    }
	 std::cout 	<< "test" << size << " \n";
	Zombie	*horde = zombieHorde(size, name);
	if (horde == NULL)
		return ;
	for (int i = 0; i < size; ++i)
		horde[i].announce();
	delete [] horde;
}

int	main(void)
{
	testHorde(5, "Zombie");
	testHorde(25, "Zombie");
	testHorde(-1, "Zombie");
	return 0;
}