/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:53:21 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/22 12:26:38 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	ifOnlySpaces(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
		if (!std::isspace(input[i]))
			return (0);	
	return (1);
}

std::string	getInput(const std::string input)
{
	std::string buffer;
	while (1)
	{
		if (ifOnlySpaces(buffer) || buffer.empty())
			std::cout << input;
		else
			break ;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
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
	num = std::atoi(index.c_str());
	return (num);
}

int	PhoneBook::searchContacts(void)
{
	int num;
	
	this->displayContacts();
	if (this->Contacts[0].getFirstName().empty())
		return (std::cout << "The Phonebook is empty\n" << std::endl, 0);
	num = getIndex();
	while (1)
	{
		if (num < 1 || num > MAX)
			std::cout << C_DRED << "Invalid index" << C_RESET << std::endl;
		else if (num > 0 & num < MAX + 1)
		{
			if (this->Contacts[num - 1].getFirstName().empty())
				std::cout << C_DBLUE "Invalid choice. This contact does not exist yet" C_RESET << std::endl;
			else
				break ;
		}
		num = getIndex();
	}
	std::cout << "First name: " << this->Contacts[num - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->Contacts[num - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->Contacts[num - 1].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->Contacts[num - 1].getPhoneNumber() << std::endl;
	std::cout << "Dark Secret: " << this->Contacts[num - 1].getDarkSecret() << std::endl;	
	std::cin.clear();
	return (0);
}

PhoneBook::PhoneBook(void)
{
	std::cout << "\n" C_LVIOLET "✩░▒▓▆▅▃▂▁▁𝐖 𝐄 𝐋 𝐂 𝐎 𝐌 𝐄▁▁▂▃▅▆▓▒░✩" C_RESET << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Your contacts have been deleted. Goodbye!" << std::endl;
}

/*
try
{
	num = std::stoi(index);
}
catch(std::invalid_argument const& ex)
{
	// std::cout << "invalid argument: " << ex.what() << '\n';
	return (0);
}*/