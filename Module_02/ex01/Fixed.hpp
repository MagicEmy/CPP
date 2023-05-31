/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/31 15:45:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
			// An integer to store the fixed-point number value.
			int	_fixedValue;
			//A static constant integer to store the number of fractional bits. Its value
			//will always be the integer literal 8.
			static const int _fractBits;

	public:
			// A default constructor that initializes the fixed-point number value to 0.
			Fixed();
			// A constructor that takes a constant integer as a parameter.
			Fixed(const int i_num);
			// A constructor that takes a constant floating-point number as a parameter.
			Fixed(const float f_num);
			// A copy constructor.
			Fixed(const Fixed &source);
			// A destructor.
			~Fixed();
			// A copy assignment operator overload.
			Fixed& operator = (const Fixed &source);
			//An overload of the insertion («) operator 
			friend std::ostream& operator << (std::ostream& output, const Fixed& source);
			//A member function that converts float toFloat( void ) const;
			float toFloat( void ) const;
			//A member function that converts the fixed-point value to an integer value.
			int toInt( void ) const;
			// A member function that returns the raw value of the fixed-point value.
			int getRawBits( void ) const;
			// A member function that sets the raw value of the fixed-point number.
			void setRawBits( int const raw );
};


#endif
