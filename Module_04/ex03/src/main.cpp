/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 17:09:51 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main (void)
{
   	// const AbsAnimal* meta = new AbsAnimal();
	const AbsAnimal* j = new Dog();
	const AbsAnimal* i = new Cat();
	// meta->makeSound();
	std::cout << GREEN << j->getType() << " " RESET << std::endl;
	j->makeSound();
	std::cout << ORANGE << i->getType() << " " << std::endl;
	i->makeSound();
	
	// delete meta;
	delete j;
	delete i;


    return 0;
}

