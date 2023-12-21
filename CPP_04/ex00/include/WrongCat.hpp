/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:26:05 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 13:29:34 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
			WrongCat( void );
			WrongCat(const WrongCat &source);
			virtual ~WrongCat( void );
			WrongCat & operator = (const WrongCat &source);

			void makeSound( void ) const;	
};

#endif