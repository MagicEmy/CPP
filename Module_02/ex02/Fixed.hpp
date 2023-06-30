/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/30 16:37:56 by emlicame         ###   ########.fr       */
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
			//A static constant integer to store the number of fractional bits. 
			static const int _fractBits;

	public:
			Fixed();
			Fixed(const int i_num);
			Fixed(const float f_num);
			Fixed(const Fixed &source);
			~Fixed();
			
			Fixed& operator = (const Fixed &source);
			
			bool operator == (const Fixed &source) const;
			bool operator != (const Fixed &source) const;
			bool operator < (const Fixed &source) const;
			bool operator <= (const Fixed &source) const;
			bool operator > (const Fixed &source) const;
			bool operator >= (const Fixed &source) const;
			
			Fixed operator + (const Fixed &source) const;
			Fixed operator - (const Fixed &source) const;
			Fixed operator * (const Fixed &source) const;
			Fixed operator / (const Fixed &source) const;
			
			Fixed& operator ++ ( void ); //pre
			Fixed& operator -- ( void ); //pre
			Fixed operator ++ ( int );	//post
			Fixed operator -- ( int );	//post
			
			static Fixed& min (Fixed &source_1, Fixed &source_2);
			static const Fixed& min (const Fixed &source_1, const Fixed &source_2);
			static Fixed& max (Fixed &source_1, Fixed &source_2);
			static const Fixed& max (const Fixed &source_1, const Fixed &source_2);
			
			float toFloat( void ) const;
			int toInt( void ) const;
			int getRawBits( void ) const;
			void setRawBits( int const raw );
};

std::ostream& operator << (std::ostream& output, const Fixed& source);

#endif
