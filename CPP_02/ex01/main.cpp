/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:03:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/28 18:52:47 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	std::cout << "\nFixed a " << std::endl;
	Fixed 		a;
	std::cout << "\nFixed const b( 10 )" << std::endl;
	Fixed const b( 10 );
	std::cout << "\nFixed const c( 42.42f )" << std::endl;
	Fixed const c( 42.42f );
	std::cout << "\nFixed const d( b )" << std::endl;
	Fixed const d( b );
	
	std::cout << "\na = Fixed(float)" << std::endl;
	a = Fixed( 1234.4321f );
	
	
	std::cout << "\n";
	std::cout << "a is " << a << std::endl;
	std::cout << GREEN "b is " << b << RESET << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << YELLOW "d is " << d << RESET << std::endl;
	
	std::cout << "\n";
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << ORANGE "b is " << b.toInt() << " as integer" RESET << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << RED "c is " << c.toInt() << " as integer" RESET << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << RED"d is " << d.toFloat() << " as float\n" << std::endl;
	return (0);
}