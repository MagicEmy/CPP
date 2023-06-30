/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:02:03 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 11:14:47 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*An interface class is a class that has no member variables, 
and where all of the functions are pure virtual! 
The class is purely a definition, and has no actual implementation. 
Interfaces are useful when you want to define the functionality that 
derived classes must implement, but leave the details of how the derived class 
implements that functionality entirely up to the derived class.*/

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
};
#endif		//==============ICHARACTER_HPP	