/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 11:36:36 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// void checkleaks(void)
// {
// 	system("leaks -q AbstractAnimals");
// }

int	main (void)
{
	{
		std::cout << "\n" << B_CYAN BLACK "Testing animal's brain:" RESET << std::endl;

		Dog doggo;
		doggo.setIdea("Food", 1);
		std::cout << doggo.getIdea(1) << std::endl;
	
		Cat gatto;
		gatto.setIdea("Adore me human", 1);
		std::cout << "gatto 0, 1 and 2:\n" << gatto.getIdea(0) << std::endl;
		std::cout << gatto.getIdea(1) << std::endl;
		std::cout << gatto.getIdea(2) << std::endl;

		std::cout << "************************************************\n";
		Cat kitty = gatto;
	
		gatto.setIdea("Don't touch me", 2);
		kitty.setIdea("Purrrrr", 2);
		std::cout << "kitty 0, 1 and 2:\n" << kitty.getIdea(0) << std::endl;				
		std::cout << kitty.getIdea(1) << std::endl;
		std::cout << kitty.getIdea(2) << std::endl;
		
		std::cout << "************************************************\n";	
		std::cout << "gatto 0, 1 and 2 again:\n" << gatto.getIdea(0) << std::endl;
		std::cout << gatto.getIdea(1) << std::endl;
		std::cout << gatto.getIdea(2) << std::endl;	
				
	}	
	// {
	// 	std::cout << "\n" << B_CYAN BLACK "Testing deep copy" RESET << std::endl;
	// 	const AAnimal* doggo = new Dog();
	// 	const AAnimal* gatto = new Cat();
		
	// 	delete doggo;//should not create a leak
	// 	delete gatto;
		
	// 	std::cout << "\n" << B_CYAN BLACK "A bunch of animals in array:" RESET << std::endl;

	// 	const AAnimal* aBunch[8];
	// 	int i;
	// 	for (i = 0; i < 8; i++)
	// 	{
	// 		if (i < 4)
	// 			aBunch[i] = new Dog();
	// 		else
	// 			aBunch[i] = new Cat();
	// 	}
	// 	for (i = 0; i < 8; i++)
	// 	{
	// 		std::cout 	<< "Animal is of type " << aBunch[i]->getType() << " ";
	// 		aBunch[i]->makeSound();
	// 	}
	// 	for (i = 0; i < 8; i++)
	// 	{	
	// 		delete(aBunch[i]);
	// 	}
	// }
	// atexit(checkleaks);
	return (0);
}
