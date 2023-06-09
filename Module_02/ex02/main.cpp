/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:52:07 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/01 13:15:39 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;			
std::cout << ++a << std::endl;			
std::cout << a << std::endl;			
std::cout << a++ << std::endl;			
std::cout << a << std::endl;			
std::cout << b << std::endl;			
std::cout << Fixed::max( a, b ) << std::endl; 
return 0;
}
