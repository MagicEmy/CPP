/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/20 14:30:48 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main (void)
{
   	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	meta->makeSound();
	std::cout << GREEN << j->getType() << " " RESET << std::endl;
	j->makeSound();
	std::cout << ORANGE << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << RED << wrong->getType() << " " << std::endl;
	wrong->makeSound();
   	
	delete meta;
	delete j;
	delete i;
	delete wrong;

    return 0;
}

