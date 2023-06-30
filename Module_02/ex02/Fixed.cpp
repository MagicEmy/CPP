/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:02:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 16:38:21 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractBits = 8; // Initialization of static _fractBits

/* --------------- Constructors ---------------*/

Fixed::Fixed(void) : _fixedValue (0) 
{
	// std::cout 	<< "Default constructor called" << std::endl;
}

// A constructor that takes a constant integer as a parameter.
Fixed::Fixed(const int i_num) : _fixedValue (i_num << _fractBits) 
{
	// std::cout 	<< MGNT << "Int constructor called" RESET << std::endl;
}

//A constructor that takes a constant floating-point number as a parameter.
//roundf() ret value is rounded to the nearest int before being assigned to _fixedValue.
Fixed::Fixed(const float f_num) : _fixedValue (roundf(f_num * static_cast<float>(1 << _fractBits))) 
{
	// std::cout 	<< MGNT << "Float constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

/* --------------- Destructor ---------------*/

Fixed::~Fixed(void)
{
	// std::cout 	<< "Destructor is called" << std::endl;
}

/* ---------- Operator Overload Functions ---------- */
// Copy assignment operator
Fixed& Fixed::operator = (const Fixed &source)
{
	if (this == &source)
		return *this;
	setRawBits(source.getRawBits());
	return *this;
}

/* ----- Comparison Operator Overload Functions ----- */
//Equality assignment operator 
bool Fixed::operator == (const Fixed &source) const
{
	return (this->getRawBits() == source.getRawBits());
}

//Inequality assignment operator 
// It directly returns the result of the comparison operation, which is already a boolean value.
bool Fixed::operator != (const Fixed &source) const
{
	return this->getRawBits() != source.getRawBits();
}

// Less than assignment operator
bool Fixed::operator < (const Fixed &source) const
{
	return this->getRawBits() < source.getRawBits();
}

// Less than or equal assignment
bool Fixed::operator <= (const Fixed &source) const
{
	return this->getRawBits() <= source.getRawBits();
}


// Greater than assignment operator
bool Fixed::operator > (const Fixed &source) const
{
	return this->getRawBits() > source.getRawBits();
}

// Greater than or equal assignment operator
bool Fixed::operator >= (const Fixed &source) const
{
	return this->getRawBits() >= source.getRawBits();
}

/* ----- Arithmetic Operator Overload Functions ----- */

// Addition operator overload.
Fixed Fixed::operator + (const Fixed &source) const
{
	Fixed res;
	res = this->getRawBits() + source.getRawBits();
	return res;
}

// Subtraction operator overload.
Fixed Fixed::operator - (const Fixed &source) const
{
	Fixed res;
	res = this->getRawBits() - source.getRawBits();
	return res;
}

// Multiplication operator overload.
Fixed Fixed::operator * (const Fixed &source) const
{
	Fixed res;
	res = this->getRawBits() * source.getRawBits();
	return res;
}

// Division operator overload.
Fixed Fixed::operator / (const Fixed &source) const
{
	Fixed res;
	res = this->getRawBits() / source.getRawBits();
	return res;
}

/* ----- Increment / Decrement Overload Functions ----- */

// Pre-increment operator overload.
Fixed& Fixed::operator ++ (void)
{
	this->_fixedValue++;
	return *this;
}

// Pre-decrement operator overload.
Fixed& Fixed::operator -- (void)
{
	this->_fixedValue--;
	return *this;
}

// Post-increment operator overload.
Fixed Fixed::operator ++ (int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

// Post-decrement operator overload.
Fixed Fixed::operator -- (int)
{
	Fixed temp = *this;
	operator--();
	return temp;
}

/* ------------ Static Member Functions ------------ */

//Static member function min, takes as parameters two references on fixed-point numbers, 
//returns a reference to the smallest one.
Fixed& Fixed::min (Fixed &source_1, Fixed &source_2)
{
	if (source_1 < source_2)
		return source_1;
	return source_2;
}

//with constant fixed-point numbers
const Fixed& Fixed::min (const Fixed &source_1, const Fixed &source_2)
{
	if (source_1 < source_2)
		return source_1;
	return source_2;
}

Fixed& Fixed::max (Fixed &source_1, Fixed &source_2)
{
	if (source_1 > source_2)
		return source_1;
	return source_2;
}

const Fixed& Fixed::max (const Fixed &source_1, const Fixed &source_2)
{
	if (source_1 > source_2)
		return source_1;
	return source_2;
}

/* --------------- Member Functions --------------- */

//converts the fixed-point value by dividing it by (1 << _fractBits), 
float Fixed::toFloat( void ) const
{
    return static_cast<float>(_fixedValue) / static_cast<float>(1 << _fractBits);
}

int	Fixed::toInt( void ) const
{
	return _fixedValue >> _fractBits;
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	_fixedValue = raw;
}

/* --------------- Non-Member Functions --------------- */

//An overload of the insertion («) operator 
std::ostream& operator << (std::ostream& output, const Fixed& source)
{
    output << source.toFloat();
    return output;
}