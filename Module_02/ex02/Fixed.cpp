/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:02:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/31 19:58:18 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractBits = 8; // Initialization of _fractBits

Fixed::Fixed(void) : _fixedValue (0) 
{
	// std::cout 	<< "Default constructor called" << std::endl;
}

// A constructor that takes a constant integer as a parameter.
Fixed::Fixed(const int i_num) : _fixedValue (0) 
{
	_fixedValue = i_num << _fractBits;
}

//A constructor that takes a constant floating-point number as a parameter.
Fixed::Fixed(const float f_num) : _fixedValue (0) 
{
	//val returned by roundf() is rounded to the nearest int before being assigned to _fixedValue.
	_fixedValue = (roundf(f_num * (1 << _fractBits)));
}

Fixed::Fixed(const Fixed &source)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed::~Fixed(void)
{
	// std::cout 	<< "Destructor is called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator = (const Fixed &source)
{
	if (this != &source) 
	{
		_fixedValue = source.getRawBits();
	}
	return *this;
}

//An overload of the insertion («) operator 
std::ostream& operator << (std::ostream& output, const Fixed& source)
{
    output << source.toFloat();
    return output;
}


//Equality assignment operator 
bool Fixed::operator == (const Fixed &source)
{
	if (this->_fixedValue == source.getRawBits()) 
	{
		return true;
	}
	return false;
}

//Inequality assignment operator 
// It directly returns the result of the comparison operation, which is already a boolean value.
bool Fixed::operator != (const Fixed &source)
{
	return this->_fixedValue != source.getRawBits();
}

// Less than assignment operator
bool Fixed::operator < (const Fixed &source)
{
	if (this->toFloat() < source.toFloat()) 
	{
		return true;
	}
	return false;
}

// Less than or equal assignment
bool Fixed::operator <= (const Fixed &source)
{
	return this->toFloat() <= source.toFloat();
}


// Greater than assignment operator
bool Fixed::operator > (const Fixed &source)
{
	if (this->_fixedValue > source.getRawBits()) 
	{
		return true;
	}
	return false;
}

// Greater than or equal assignment operator
bool Fixed::operator >= (const Fixed &source)
{
	return this->toFloat() >= source.toFloat();
}

// A addition operator overload.
Fixed Fixed::operator + (const Fixed &source)
{
	Fixed res;
	res = this->toFloat() + source.toFloat();
	return res;
}

// A subtraction operator overload.
Fixed Fixed::operator - (const Fixed &source)
{
	Fixed res;
	res = this->toFloat() - source.toFloat();
	return res;
}

// A multiplication operator overload.
Fixed Fixed::operator * (const Fixed &source)
{
	Fixed res;
	res = this->toFloat() * source.toFloat();
	return res;
}

// A division operator overload.
Fixed Fixed::operator / (const Fixed &source)
{
	Fixed res;
	res = this->toFloat() / source.toFloat();
	return res;
}

// A pre-increment operator overload.
Fixed& Fixed::operator ++ (void)
{
	this->_fixedValue++;
	return *this;
}

// A pre-decrement operator overload.
Fixed& Fixed::operator -- (void)
{
	this->_fixedValue--;
	return *this;
}

// A post-increment operator overload.
Fixed Fixed::operator ++ (int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

// A post-decrement operator overload.
Fixed Fixed::operator -- (int)
{
	Fixed temp = *this;
	operator--();
	return temp;
}

//A static member function min that takes as parameters two references on fixed-point numbers, 
//and returns a reference to the smallest one.
Fixed& Fixed::min (Fixed &source_1, Fixed &source_2)
{
	if (source_1.toFloat() < source_2.toFloat())
		return source_1;
	return source_2;
}

const Fixed& Fixed::min (const Fixed &source_1, const Fixed &source_2) //with constant fixed-point numbers
{
	if (source_1.toFloat() < source_2.toFloat())
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
	if (source_1.toFloat() > source_2.toFloat())
		return source_1;
	return source_2;
}

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