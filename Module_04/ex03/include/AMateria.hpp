/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:52:12 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 11:47:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"
#include "ICharacter.hpp"

class AMateria
{
	protected:
			std::string _AMateriaType;
	public:
			AMateria();
			AMateria(std::string const & type);
			AMateria(const AMateria &source);
			virtual ~AMateria( void );
			AMateria & operator = (const AMateria &source);

			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
};

#endif		//==============AMATERIA_HPP		