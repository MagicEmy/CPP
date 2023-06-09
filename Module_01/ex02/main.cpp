/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:45:21 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 18:59:43 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main (void)
{
	//A string variable initialized to "HI THIS IS BRAIN"
	std::string brain = "HI THIS IS BRAIN";	
	//stringPTR: A pointer to the string.
	std::string *stringPTR = &brain;
	//stringREF: A reference to the string.
	std::string &stringREF = brain;

	//print memory address of the string variable.
	std::cout << "The memory address of brain is: " << &brain << std::endl;
	//The memory address held by stringPTR.
	std::cout << "The memory address of held by stringPTR: " << stringPTR << std::endl;
	//The memory address held by stringREF.
	std::cout << "The memory address of held by stringREF: " << &stringREF << std::endl;
	
	//print the value of the string variable.
	std::cout << "Value of brain: " << brain << std::endl;
	//print The value pointed to by stringPTR.
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	//The value pointed to by stringREF.
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	return 0;
}

