/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:24:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/10 17:37:06 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include "Colors.hpp"

class WrongAnimal
{
	protected:
			std::string _wrongAnimalType;

	public:
			WrongAnimal( void );
			WrongAnimal( std::string type );
			WrongAnimal(const WrongAnimal &source);
			virtual ~WrongAnimal( void );
			WrongAnimal & operator = (const WrongAnimal &source);

			const std::string& getType( void ) const;
			
			void makeSound( void ) const;
};

#endif		//==============ANIMAL_HPP	