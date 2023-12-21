/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:24:22 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 16:54:58 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(void) : _fixedValue (0) 
{
	std::cout 	<< MGNT "Default constructor called" RESET << std::endl;
	return;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << MGNT "Copy constructor called" RESET << std::endl;
	*this = source;
	return;
}

Fixed::~Fixed(void)
{
	std::cout 	<< BLUE  "Destructor is called" RESET << std::endl;
	return;
}

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << CYAN  "Copy assignment operator called" RESET << std::endl;
	if (this == &source)
		return *this;
	setRawBits(source.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cerr << DMGNT << "getRawBits member function called" RESET << GREEN  << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	_fixedValue = raw;
}
