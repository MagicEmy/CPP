/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:36:54 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/06 17:31:52 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : ICharacter(), _name(" ")
{
	for (int i = 0; i < maxMateria; i++)
		_inventory[i] = nullptr;
	std::cout 	<< "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	for (int i = 0; i < maxMateria; i++)
		_inventory[i] = nullptr;
	std::cout 	<< ORANGE "Character constructor called" << RESET << std::endl;
}

Character::Character(const Character &source) : _name(source._name)
{
	*this = source;
}

Character::~Character()
{
	for (int i = 0; i < maxMateria; i++)
			delete _inventory[i];
	std::cout 	<< DMGNT "Character destructor called " << RESET << std::endl;
}

Character& Character::operator = (const Character &source)
{
	if (this == &source)
		return *this;

	_name = source._name;
	for (int i = 0; i < maxMateria; i++)
		_inventory[i] = nullptr;
	for (int i = 0; i < maxMateria; i++)
	{
		if (source._inventory[i] != nullptr)
			_inventory[i] = source._inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < maxMateria; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > maxMateria)
		return;
	delete _inventory[idx]; // ????
	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= maxMateria)
		return ;
	this->_inventory[idx]->use(target);
	std::cout 	<< "You cast a spell on " << target.getName() << std::endl;
}