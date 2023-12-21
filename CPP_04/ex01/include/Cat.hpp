/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:27 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/10 18:12:21 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	private:
			Brain	*_brain;
	public:
			Cat( void );
			Cat(const Cat &source);
			virtual ~Cat( void );
			Cat & operator = (const Cat &source);

			virtual void makeSound( void ) const;
			const std::string& getIdea( int i) const;
			void  setIdea(std::string newIdea, int i);
};

#endif
