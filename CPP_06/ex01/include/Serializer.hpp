/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 19:14:55 by emlicame      #+#    #+#                 */
/*   Updated: 2023/11/22 12:38:41 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{	
	private:
			Serializer( void );
			Serializer(const Serializer& src);
			
	public:
			~Serializer( void );
			Serializer& operator =(const Serializer& src);

			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};

#endif

/*
Serialization:

The process of converting complex data structures or objects into a linear \or binary format. This format can be easily stored in files, 
transmitted over networks, or sent between different programs or systems.

Deserialization:

The process of reconstructing a complex data structure or object from a serialized format.
It takes the serialized data and converts it back into its original form.
*/