/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:02:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/31 13:46:17 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8; // Initialization of _fractBits

Fixed::Fixed(void) : _fixedValue (0) 
{
	std::cout 	<< "Default constructor called" << std::endl;
}

// A constructor that takes a constant integer as a parameter.
//It converts it to the corresponding fixed-point value. The fractional bits value is 8.

/* Fixed point math uses the top X bits of an integer as the whole number part of a 
floating point number and the bottom Y bits as the fractional part. The way you 
shift the float Y bits so that it fits in an integer is to multiply by float(2^Y).*/
/*calculates the fixed-point value by shifting i_num to the left by _fractBits
This effectively multiplies num by 2^8, since 
shifting left by n is equivalent to multiplying by 2^n.*/
Fixed::Fixed(const int i_num) : _fixedValue (0) 
{
	std::cout 	<< "Int constructor called" << std::endl;
	_fixedValue = i_num << _fractBits;
}

//A constructor that takes a constant floating-point number as a parameter.
//It converts it to the corresponding fixed-point value.
Fixed::Fixed(const float f_num) : _fixedValue (0) 
{
	std::cout 	<< "Float constructor called" << std::endl;
	_fixedValue = (round(f_num * (1 << _fractBits)));
}
/* The round functions return the integral value nearest to x rounding half-way 
cases away from zero, regardless of the current rounding direction.
std::round takes a single argument of type double or float. 
It returns the rounded value as a double.
When you pass a floating-point value to std::round, 
it examines the value and determines the nearest integer based on the rounding rules.
If the fractional part of the value is less than 0.5, 
std::round rounds the value towards the nearest integer with a lesser value.*/

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

/* When outputting floating point numbers, std::cout has a default precision of 6. 
That is, it assumes all floating point variables are only significant to 6 digits 
(the minimum precision of a float), and hence it will truncate anything after that.
double until 12, precision can be set with  std::cout.precision(12);*/
std::ostream& operator << (std::ostream& output, const Fixed& source)
{
    // Convert the fixed-point value back to floating-point representation for output
    output << source.toFloat();
    return output;
}

/*
static_cast is a C++ specific casting operator that performs compile-time type checking. 
It is considered safer because it performs a range check during compilation, 
ensuring that the conversion is valid. It provides clearer intent and better type safety.

(float) is a C-style cast that performs a direct type conversion. 
It does not perform any compile-time checks, 
so it allows conversions that may not be safe. 
C-style casts can be more error-prone because they allow different types of conversions, 
such as const_cast and reinterpret_cast, which may not be intended.
*/

//converts the fixed-point value by dividing it by (1 << _fractBits), 
//which effectively shifts the value to the right by _fractBits bits, 
//resulting in the corresponding floating-point representation.
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
