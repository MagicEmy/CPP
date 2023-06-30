/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:02:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 17:00:36 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8; // Initialization of static _fractBits

/* --------------- Constructors ---------------*/

Fixed::Fixed(void) : _fixedValue (0) 
{
	std::cout 	<< MGNT "Default constructor called" RESET << std::endl;
}

// A constructor that takes a constant integer as a parameter.
//It converts it to the corresponding fixed-point value. The fractional bits value is 8.

/* calculates the fixed-point value by shifting i_num to the left by _fractBits
This effectively multiplies num by 2^8, since shifting left by n 
is equivalent to multiplying by 2^n.*/
Fixed::Fixed(const int i_num) : _fixedValue (i_num << _fractBits) 
{
	std::cout 	<< MGNT << "Int constructor called" RESET << std::endl;
}

//A constructor that takes a constant floating-point number as a parameter.
//It converts it to the corresponding fixed-point value.
Fixed::Fixed(const float f_num) : _fixedValue (roundf(f_num * static_cast<float>(1 << _fractBits))) 
{
	std::cout 	<< GREEN "Float constructor called" RESET << std::endl;
}
//roundf() ret value is rounded to the nearest int before being assigned to _fixedValue.

Fixed::Fixed(const Fixed &source)
{
	std::cout << DMGNT "Copy constructor called" RESET << std::endl;
	*this = source;
}

/* --------------- Destructor ---------------*/

Fixed::~Fixed(void)
{
	std::cout 	<< BLUE "Destructor is called" RESET << std::endl;
}

/* ---------- Operator Overload Functions ---------- */

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << YELLOW "Copy assignment operator called" RESET << std::endl;
	if (this == &source)
		return *this;
	setRawBits(source.getRawBits());
	return *this;
}

/* --------------- Member Functions --------------- */

//converts the fixed-point value by dividing it by (1 << _fractBits), 
//which effectively shifts the value to the right by _fractBits bits, 
float Fixed::toFloat( void ) const
{
    // Divide the fixed-point value by (1 << _fractBits) to get the floating-point representation
    return static_cast<float>(_fixedValue) / static_cast<float>(1 << _fractBits);
}

int	Fixed::toInt( void ) const
{
	return _fixedValue >> _fractBits;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	_fixedValue = raw;
	std::cout << "getRawBits member function called" << std::endl;
}

/* --------------- Non-Member Functions --------------- */

/* When outputting floating point numbers, std::cout has a default precision of 6. 
double until 12, precision can be set with  std::cout.precision(num until 12);*/
std::ostream& operator << (std::ostream& output, const Fixed& source)
{
    // Convert the fixed-point value back to floating-point representation for output
    output << source.toFloat();
    return output;
}