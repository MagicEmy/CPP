/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 19:19:55 by emlicame      #+#    #+#                 */
/*   Updated: 2023/11/22 13:26:07 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <limits>
#include <iostream>


Serializer::Serializer( void ){}
Serializer::~Serializer( void ){}

Serializer::Serializer(const Serializer &src){
	*this = src;
}

Serializer &Serializer::operator =(const Serializer &src){
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr){
	if (ptr == 0)
		return 0;
	return reinterpret_cast<uintptr_t>(ptr);	
}

Data *Serializer::deserialize(uintptr_t raw){
	if (raw == 0)
		return nullptr;
	Data *deserialized = reinterpret_cast<Data *>(raw);
	if (deserialized == nullptr)
		return nullptr;
	try
	{
		if (deserialized->i < std::numeric_limits<int>::min() || \
		deserialized->i > std::numeric_limits<int>::max())
			throw std::out_of_range ("out of range");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return nullptr;
	}
	return deserialized;
}

/*
reinterpret_cast is used to perform a low-level type cast from a pointer to an integer. 
It doesn't change the actual data but rather treats the memory content 
as if it were of the target type. 
*/