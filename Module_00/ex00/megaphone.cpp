/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 17:16:41 by emanuela      #+#    #+#                 */
/*   Updated: 2023/05/01 17:27:19 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv[i])
		std::cout << capitalize(argv[i++]);
	std::cout << std::endl;
	return (0);
}
