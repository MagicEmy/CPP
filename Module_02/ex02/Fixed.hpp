/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:19 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/31 19:58:56 by emlicame         ###   ########.fr       */
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
			//A static constant integer to store the number of fractional bits. 
			static const int _fractBits;

	public:
			Fixed();
			Fixed(const int i_num);
			Fixed(const float f_num);
			Fixed(const Fixed &source);
			~Fixed();
			
			Fixed& operator = (const Fixed &source);
			
			friend std::ostream& operator << (std::ostream& output, const Fixed& source);
			
			bool operator == (const Fixed &source);
			bool operator != (const Fixed &source);
			bool operator < (const Fixed &source);
			bool operator <= (const Fixed &source);
			bool operator > (const Fixed &source);
			bool operator >= (const Fixed &source);
			
			Fixed operator + (const Fixed &source);
			Fixed operator - (const Fixed &source);
			Fixed operator * (const Fixed &source);
			Fixed operator / (const Fixed &source);
			
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


#endif
