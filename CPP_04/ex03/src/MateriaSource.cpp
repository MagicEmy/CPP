/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:15:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 12:04:37 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < maxSkills; i++)
		_materiaLearned[i] = nullptr;
	std::cout 	<< "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	*this = source;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < maxSkills; i++)
		delete _materiaLearned[i];
	std::cout 	<< "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource &source)
{
	if (this == &source)
		return *this;
	for (int i = 0; i < maxSkills; i++)
	{
		if (_materiaLearned[i] != nullptr)
			_materiaLearned[i] = source._materiaLearned[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* mate)
{
	for (int i = 0; i < maxSkills; i++)
	{
		if (_materiaLearned[i] == nullptr)
		{
			_materiaLearned[i] = mate;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < maxSkills; i++)
	{
		if (_materiaLearned[i] != nullptr && _materiaLearned[i]->getType() == type )
			return (_materiaLearned[i]->clone());
	}
	return (nullptr);
}
