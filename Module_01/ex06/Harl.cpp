/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:00:05 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 14:15:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout 	<< "Harl loves complaining" << std::endl;
}
			
Harl::~Harl(void)
{
	std::cout 	<< "Harl stoped complaining" << std::endl;
}

void	Harl::debug( void )
{
	std::cout 	<< GREEN "[ DEBUG ] \n"
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!" RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout 	<< YELLOW "[ INFO ] \n"
				<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!" RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout 	<< ORANGE "[ WARNING ] \n"
				<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years whereas you started working "
				<< "here since last month." RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout 	<< RED "[ ERROR ] \n"
				<< "This is unacceptable! "
				<< "I want to speak to the manager now." RESET << std::endl;
}

void Harl::complain( std::string level )
{
	int num_level = 0;
	std::string levelsOn[] = {
		""
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == levelsOn[i])
			num_level = i;
	}
	
	switch (num_level)
	{
		case 1 :
			Harl::debug();
			break;
		case 2 :
			Harl::info();
			break;
		case 3 :
			Harl::warning();
			break;
		case 4 :
			Harl::error();
			break;
		default :
			std::cout 	<< ORANGE "[ LOADING ] \n"
						<< "Loading more energy for complaining harder..." 
						<< RESET << std::endl;
			break;
	}
	
}
