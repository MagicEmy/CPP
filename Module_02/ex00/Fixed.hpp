/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:16:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 12:41:15 by emlicame         ###   ########.fr       */
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

/*
The concept behind the Orthodox Canonical Form is to ensure that classes 
properly handle resource management, copying, and destruction. 
By following this guideline, you establish a consistent and 
safe behavior for your classes.
Copy Constructor: This function creates a new object as a copy of an existing object.
It is responsible for initializing the new object's data members by copying 
the values from the original object. 
Proper implementation of the copy constructor is essential to avoid shallow copies 
and ensure deep copies of any dynamically allocated resources.

Copy Assignment Operator: This function is responsible for assigning the values 
of one object to another after both objects have already been constructed. 
It is invoked when you assign one object to another using the assignment operator (=). 
Similar to the copy constructor, the copy assignment operator should properly handle
resource management and avoid issues like memory leaks or invalid object states.

Destructor: This function is called when an object is destroyed 
or goes out of scope. It is responsible for releasing any resources held 
by the object, such as dynamically allocated memory, file handles, 
or network connections. 
The destructor should clean up and deallocate any resources 
to prevent leaks and ensure proper destruction.

The Orthodox Canonical Form ensures that these three functions are 
implemented correctly and consistently for classes managing resources. 
By doing so, you prevent issues like double deletion, 
resource leaks, or invalid object states.
*/