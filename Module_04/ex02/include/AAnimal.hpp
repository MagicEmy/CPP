/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:54:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 16:31:20 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

class AAnimal
{
	protected:
			std::string _animalType;

	public:
			AAnimal( void );
			AAnimal( std::string type );
			AAnimal(const AAnimal &source);
			virtual ~AAnimal( void );
			AAnimal & operator = (const AAnimal &source);

			const std::string& getType( void ) const;
			
			virtual void makeSound( void ) const = 0; 		// pure virtual function
			//Animal is now an abstract base class, and can not be instantiated.
};

#endif		//==============AANIMAL_HPP	
