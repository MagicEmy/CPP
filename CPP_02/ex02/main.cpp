/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:52:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 15:10:14 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
		
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed const c( Fixed( 5.05f ) / Fixed( 0 ) );
Fixed d( Fixed( 5.05f ) * Fixed( 3 ) );

std::cout << GREEN "a = " << a << RESET << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			

a = Fixed (1);
std::cout << GREEN "a = " << a << RESET << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << "++a = " << ++a  << std::endl;			
std::cout << GREEN "a = " << a << RESET << std::endl;			
std::cout << "a++ = " << a++  << std::endl;			
std::cout << GREEN "a = " << a << RESET << std::endl;			
std::cout << "\nb = " << b << std::endl;			
std::cout << GREEN "\nc = " << c << RESET << std::endl;			
std::cout << "\nd = " << d << std::endl;			
std::cout << "++d = " << ++d << std::endl;			

std::cout << YELLOW "\nFixed::min = " << Fixed::min( a, b ) << RESET << std::endl; 
std::cout << RED "Fixed::max = " << Fixed::max( a, b ) << RESET << std::endl; 

//test the different functions
//comparisons
std::cout << GREEN "\nDifferent functions comparison with floats" RESET << std::endl;
a = Fixed( 10.5f );
d = Fixed( -10.5f );

std::cout << "\na is " << a << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << GREEN "\nComparison" << std::endl;
std::cout << "a > d = " << (a>d) << std::endl;
std::cout << "a > d = " << (a<d) << std::endl;
std::cout << "a >= d = " << (a >= d) << std::endl;
std::cout << "a <= d = " << (a <= d) << std::endl;
std::cout << "a == d = " << (a == d) << std::endl;
std::cout << "a != d = " << (a != d) << std::endl;

//arithmetic operators
std::cout <<RESET "\nAritmetic" << std::endl;
std::cout << "a + d = " <<(a + d) << std::endl;
std::cout << "a - d = " << (a - d) << std::endl;
std::cout << "a * d = " << (a * d) << std::endl;
std::cout << "a / d = " << (a / d) << std::endl;

// //increment / decrement
std::cout << GREEN "\nIncrement/decrement" << std::endl;
std::cout << "++a " << ++a << std::endl;
std::cout << "a++ " << a++ << " a " << a << std::endl;
std::cout << "--a " << --a << std::endl;
std::cout << "a-- " << a-- << " a " << a << std::endl;

//min max
std::cout << RESET "\nMin Max" << std::endl;
std::cout << "Min " << Fixed::min(a, d) << std::endl;
std::cout << "Max " << Fixed::max(a, d) << std::endl;

Fixed const e = a;
Fixed const f = d;
std::cout << GREEN "\nMin Max const" << std::endl;
std::cout << "Min " << Fixed::min(e, f) << std::endl;
std::cout << "Max " << Fixed::max(e, f) << RESET << std::endl;

return 0;
}