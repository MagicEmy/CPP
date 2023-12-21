/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:27 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/10 18:15:02 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
			Brain 		*_brain;
	public:
			Dog( void );
			Dog(const Dog &source);
			virtual ~Dog( void );
			Dog & operator = (const Dog &source);

			virtual void makeSound( void ) const;
			const std::string& getIdea( int i) const;
			void  setIdea(std::string newIdea, int i);

			Brain *getBrain();
};

#endif