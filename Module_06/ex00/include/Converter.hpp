/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:47 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/26 18:35:17 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>

enum Type {
	typeChar,
	typeInt,
	typeFloat,
	typeDouble,
	typeError
};


class Converter
{
	public:
			Converter( void );
			Converter(const Converter& src);
			~Converter( void );
			Converter& operator =(const Converter& src);

			static void convert(const std::string& input);
};

#endif
