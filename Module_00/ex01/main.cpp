/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:38:28 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/15 18:32:14 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phone;
	std::string input;
	
    std::cout	<< C_DBLUE "to	" C_ITALIC C_BOLD "My Awesome PhoneBook\n"
				<< C_RESET C_DBLUE "This application accept the following commands:\n"
				<< "ADD to add a contact, SEARCH to look for a name, "
				<< "EXIT to quit the application\n" 
				<< "The input entry is case sensitive, please enter the "
				<< "input in capital letters \n" C_RESET << std::endl;

    while (input.compare("EXIT") != 0)
    {
		std::cout << C_DMGNT "Enter a command: ADD, SEARCH or EXIT: " C_RESET;
		std::cin.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		if (input.compare("ADD") == 0)
			phone.addContacts();
		else if (input.compare("SEARCH") == 0)
			phone.searchContacts();
		else if (input.compare("EXIT") != 0)
			std::cout 	<< C_DRED "\"" <<  input 
						<< "\" is an invalid input" C_RESET << std::endl;
		
    }
	return (0);
}
/*
cin.getline(temp, STRLEN);
if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
*/