/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Converter.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 15:50:47 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/01 14:55:56 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cfloat>

enum Type {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO,
	TYPE_ERROR
};
 
class Converter
{
	private:
			Converter( void );
			Converter(const Converter& src);
			~Converter( void );
			Converter& operator =(const Converter& src);
	
	public:

			static void convert(const std::string& input);
};

#endif
