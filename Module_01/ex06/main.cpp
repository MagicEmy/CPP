/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:38:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:31:55 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int argc, char *argv[])
{
	Harl mrHarl;

	if (argc != 2)
	{
		std::cout 	<< RED "Wrong input. Please enter 1 level of complaint\n" RESET  
				 	<< DRED "Possible choices: \n" RESET
					<< GREEN "DEBUG \n" RESET
					<< YELLOW "INFO \n" RESET
					<< ORANGE "WARNING \n" RESET
					<< RED "ERROR" RESET << std::endl;
		return (1);
	}
	std::string input = argv[1];
	mrHarl.complain(argv[1]);	
	return (0);
}