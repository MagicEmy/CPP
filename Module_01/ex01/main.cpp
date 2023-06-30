/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:44 by emlicame          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/20 15:27:37 by emlicame         ###   ########.fr       */
=======
/*   Updated: 2023/06/16 15:15:31 by emlicame         ###   ########.fr       */
>>>>>>> 1a93750e1d2cffadf21150e82d5237dd4e4f4da0
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testHorde(int size, std::string name)
{
	Zombie	*horde = zombieHorde(size, name);
	if (horde == nullptr)
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