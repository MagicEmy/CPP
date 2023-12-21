/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:16:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/09/01 14:46:11 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RED		"\x1b[38;2;255;0;0m"
#define DRED	"\x1b[38;2;128;0;0m"
#define GREEN	"\x1b[38;2;0;255;0m"
#define YELLOW	"\x1b[38;2;255;255;0m"
#define ORANGE	"\x1b[38;2;255;128;0m"
#define CYAN	"\x1b[38;2;0;255;255m"
#define BLUE	"\033[34m"
#define MGNT	"\x1b[38;2;255;0;255m"
#define DMGNT	"\x1b[38;2;128;0;128m"
#define RESET	"\033[0m"

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
