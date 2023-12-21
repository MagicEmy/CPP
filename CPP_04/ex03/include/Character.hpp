/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:02:03 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 11:21:21 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character :  public ICharacter
{
	private:
			static const int maxMateria = 4;
			
			std::string _name;
			AMateria *_inventory[maxMateria];
	public:
			Character( void );
			Character(std::string name);
			virtual ~Character( void );
			Character(const Character &source);
			Character & operator = (const Character &source);
			
			std::string const & getName() const;
			virtual void equip(AMateria* m);
			virtual void unequip(int idx);
			virtual void use(int idx, ICharacter& target);

};
#endif		//==============CHARACTER_HPP	

/*
The Character possesses an inventory of 4 slots, which means 4 Materias at most.
The inventory is empty at construction. They equip the Materias in the first empty slot
they find. This means, in this order: from slot 0 to slot 3. In case they try to add
a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
(but still, bugs are forbidden). The unequip() member function must NOT delete the
Materia!
Handle the Materias your character left on the floor as you like.
Save the addresses before calling unequip(), or anything else, but
don’t forget that you have to avoid memory leaks.
*/