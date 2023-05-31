/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:38:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/22 18:11:49 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int argc, char *argv[])
{
	Harl mrHarl;

	if (argc != 2)
	{
		std::cout 	<< "Wrong input. Please enter 1 level of complaint\n"
				 	<< "Possible choices: \n"
					<< "DEBUG \n"
					<< "INFO \n"
					<< "WARNING \n"
					<< "ERROR" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	mrHarl.complain(argv[1]);	
	return (0);
}