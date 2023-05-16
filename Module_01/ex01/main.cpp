/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:44 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 18:43:12 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	const int SIZE = 5;
	
	Zombie* horde = zombieHorde( SIZE, "John Doe");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < SIZE; ++i)
		horde[i].announce();
	delete [] horde;
	return 0;
}