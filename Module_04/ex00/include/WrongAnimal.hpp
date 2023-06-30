/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:24:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 12:19:07 by emlicame         ###   ########.fr       */
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
			WrongAnimal(const WrongAnimal &source);
			virtual ~WrongAnimal( void );
			WrongAnimal & operator = (const WrongAnimal &source);

			const std::string& getType( void ) const;
			void setType(std::string type);
			
			void makeSound( void ) const;
};

#endif		//==============ANIMAL_HPP	