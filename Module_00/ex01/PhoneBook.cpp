/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 17:30:20 by emanuela      #+#    #+#                 */
/*   Updated: 2023/05/01 17:41:53 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    start_session(void)
{
    std::string input;
    
	std::cout << "Please enter your choice\n";
    while (input.compare("EXIT") != 0)
    {
        std::cin >> input;
    }
}

PhoneBook::PhoneBook(void)
{
    std::cout << "Welcome to your PhoneBook\n";
    std::cout << "This application accept the following commands\n";
    std::cout << "ADD to add a contact, SEARCH to look for a name or EXIT to quit the application\n";
    std::cout << "The input entry is case sensitive, please enter the input all in capital letters\n";
    start_session();
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Your contacts have been deleted. Goodbye!" << std::endl;
}

int	main(void)
{
	PhoneBook phone;
	
	return (0);
}