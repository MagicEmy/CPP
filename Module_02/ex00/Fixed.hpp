/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:16:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/31 13:53:14 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			// An integer to store the fixed-point number value.
			int	_fixedValue;
			//A static constant integer to store the number of fractional bits. Its value
			//will always be the integer literal 8.
			static const int _fractBits = 8;

	public:
			// A default constructor that initializes the fixed-point number value to 0.
			Fixed();
			// A copy constructor.
			Fixed(const Fixed &source);
			// A destructor.
			~Fixed();
			// A copy assignment operator overload.
			Fixed & operator = (const Fixed &source);
			
			// A member function that returns the raw value of the fixed-point value.
			int getRawBits( void ) const;
			// A member function that sets the raw value of the fixed-point number.
			void setRawBits( int const raw );
};

#endif
