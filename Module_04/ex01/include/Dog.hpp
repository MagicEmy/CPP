/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:27 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 13:31:43 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
			Brain 		*_brain;
	public:
			Dog( void );
			Dog(const Dog &source);
			virtual ~Dog( void );
			Dog & operator = (const Dog &source);

			virtual void makeSound( void ) const;	
};

#endif