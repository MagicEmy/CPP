/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 09:51:34 by emlicame         ###   ########.fr       */
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
	std::cout << "What is the sound of " << meta->getType() << " " RESET << std::endl;
	meta->makeSound();
	std::cout << "What is the sound of " << j->getType() << " ";
	j->makeSound(); 
	std::cout << "What is the sound of " << i->getType() << " ";
	i->makeSound();
	std::cout << "What is the sound of " << wrong->getType() << " ";
	wrong->makeSound();
   	
	delete meta;
	delete j;
	delete i;
	delete wrong;

    return 0;
}

