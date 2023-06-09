/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:00:05 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:30:12 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	levelsOn[0] = "DEBUG";
	levelsOn[1]	= "INFO";
	levelsOn[2]	= "WARNING";
	levelsOn[3]	= "ERROR";
	std::cout 	<< DMGNT "Harl loves complaining" RESET << std::endl;
}
			
Harl::~Harl(void)
{
	std::cout 	<< BLUE "Harl stopped complaining" RESET << std::endl;
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
	int size = sizeof(levelsOn) / sizeof(levelsOn[0]);
	int num_level = 5;
	for (int i = 0; i < size; i++)
	{
		if (level == levelsOn[i])
			num_level = i;
	}
	
	switch (num_level)
	{
		case 0 :
			Harl::debug();
		case 1 :
			Harl::info();
		case 2 :
			Harl::warning();
		case 3 :
			Harl::error();
			break;
		default :
			std::cout 	<< MGNT "[ " << level << " ]" << "\n"
						<< "Harl doesn't complain at this level...yet" 
						<< RESET << std::endl;
			break;
	}
}
