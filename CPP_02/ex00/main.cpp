/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:17:08 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/28 11:47:57 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	std::cout << GREEN "\nFixed a;" RESET<< std::endl;
	Fixed a;
	std::cout << GREEN "\nFixed b( a );" RESET<< std::endl;
	Fixed b( a );
	std::cout << GREEN "\nFixed c;" RESET<< std::endl;
	Fixed c;
	std::cout << GREEN "\nc = b;" RESET<< std::endl;
	c = b;
	std::cout << YELLOW "\na.getRawBits() \n" << a.getRawBits() << std::endl;
	std::cout << ORANGE "\nb.getRawBits() \n" << b.getRawBits() << std::endl;
	std::cout << RED "\nc.getRawBits() \n" << c.getRawBits() << "\n" << std::endl;
return 0;
}
