/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:24:22 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/31 13:52:57 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedValue (0) 
{
	std::cout 	<< "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	// _fixedValue = source._fixedValue;
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
	
}

Fixed::~Fixed(void)
{
	std::cout 	<< "Destructor is called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source) 
	{
		_fixedValue = source.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	_fixedValue = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}
