/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:53:21 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/05 20:19:53 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	getInput(const std::string input)
{
	std::string buffer;
	while (1)
	{
		if (buffer.empty())
			std::cout << input;
		else
			break ;
		std::getline(std::cin, buffer);
		std::cout << std::endl;
	}
	return (buffer);
}

void	PhoneBook::addContacts(void)
{
	static int index = 0;
	std::cin.clear();
	this->Contacts[index].setFirstName(getInput("Enter First name: "));
	this->Contacts[index].setLastName(getInput("Enter Last name: "));
	this->Contacts[index].setNickName(getInput("Enter Nickname: "));
	this->Contacts[index].setPhoneNumber(getInput("Enter Phone Number: "));
	this->Contacts[index].setDarkSecret(getInput("Enter Dark Secret: "));
	index++;
	if (index == MAX)
		index = 0;
}

void		PhoneBook::displayContacts(void)
{
	int number;
	
	number = 1;
	std::cout 	<< "+" << std::setfill('-') << std::setw(44) << "+" << "\n"
				<< std::setfill(' ')
				<< "|" << std::setw(10) << "Index" 
				<< "|" << std::setw(10) << "First name"
				<< "|" << std::setw(10) << "Last name"
				<< "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	while (number <= MAX && !Contacts[number - 1].getFirstName().empty())
	{
		std::cout 	<< "|" << std::setw(10) << number;
					// << "|" << std::setw(10);
		if (Contacts[number - 1].getFirstName().length() <= 10)
			std::cout << "|" << std::setw(10) << Contacts[number - 1].getFirstName();
		else
			std::cout << "|" << Contacts[number - 1].getFirstName().substr(0, 9) << '.';
		if (Contacts[number - 1].getLastName().length() <= 10)
			std::cout << "|" << std::setw(10) << Contacts[number - 1].getLastName();
		else
			std::cout << "|" << Contacts[number - 1].getLastName().substr(0, 9) << '.';
		if (Contacts[number - 1].getNickName().length() <= 10)
			std::cout << "|" << std::setw(10) << Contacts[number - 1].getNickName();
		else
			std::cout << "|" << Contacts[number - 1].getNickName().substr(0, 9) << '.';
		std::cout	<< "|" << std::endl;
		number++;
	}
	std::cout 	<< "+" << std::setfill('-') << std::setw(44) << "+" << "\n"
				<< std::setfill(' ');
}

int		getIndex()
{
	std::string index;
	int num;
	
	std::cout << "Please enter the index of chosen contact" << std::endl;
	std::getline(std::cin, index);
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	try
	{
		num = std::stoi(index);
	}
	catch(std::invalid_argument const& ex)
	{
        // std::cout << "invalid argument: " << ex.what() << '\n';
		return (0);
	}
	return (num);
}

void	PhoneBook::searchContacts(void)
{
	int num;
	
	this->displayContacts();
	num = getIndex();
	while (num < 1 || num > MAX)
	{
		std::cout << "Invalid index" << std::endl;
		num = getIndex();
	}
	std::cout << "First name: " << this->Contacts[num - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->Contacts[num - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->Contacts[num - 1].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->Contacts[num - 1].getPhoneNumber() << std::endl;
	std::cout << "Dark Secret: " << this->Contacts[num - 1].getDarkSecret() << std::endl;	
	std::cin.clear();
}

PhoneBook::PhoneBook(void)
{
	std::cout << C_LVIOLET "✩░▒▓▆▅▃▂▁▁𝐖 𝐄 𝐋 𝐂 𝐎 𝐌 𝐄▁▁▂▃▅▆▓▒░✩" C_RESET << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Your contacts have been deleted. Goodbye!" << std::endl;
}


