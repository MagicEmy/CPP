/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:00:05 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/14 16:03:50 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	ptrToFn[0] = &Harl::debug;
	ptrToFn[1] = &Harl::info;
	ptrToFn[2] = &Harl::warning;
	ptrToFn[3] = &Harl::error;
	ptrToFn[4] = &Harl::grumbling;
	
	_levelsOn[0] = "DEBUG";
	_levelsOn[1] = "INFO";
	_levelsOn[2] = "WARNING";
	_levelsOn[3] = "ERROR";
	std::cout 	<< CYAN "Harl loves complaining" RESET << std::endl;
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

void	Harl::grumbling()
{
	std::cout 	<< MGNT "[ GRUMBLING ] \n"
				<< "Harl is grumbling something, getting more energy for complaining harder" 
				<< RESET << std::endl;
}

void Harl::complain( std::string level )
{
	// Call the member function through the pointer
	int i = 0;
	while (i < 4)
	{
		if (level == _levelsOn[i])
			break;
		i++;
	}
	(this->*ptrToFn[i])();
}
