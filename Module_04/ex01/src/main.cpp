/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 13:22:10 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main (void)
{
   	const Animal* doggo = new Dog();
	const Animal* gatto = new Cat();
	delete doggo;//should not create a leak
	delete gatto;
	const Animal* aBunch[8];
	int i;
	for (i = 0; i < 8; i++)
	{
		if (i < 4)
			aBunch[i] = new Dog();
		else
			aBunch[i] = new Cat();
	}
	for (i = 0; i < 8; i++)
	{
		delete(aBunch[i]);
	}
	return 0;
}

