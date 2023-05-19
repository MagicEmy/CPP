/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:51:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/18 17:32:37 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string	capitalize(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper((char)str[i]);
	return (str);	
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv[i])
		std::cout << capitalize(argv[i++]) << " ";
	std::cout << std::endl;
	return (0);
}
