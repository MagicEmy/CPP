/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:06:38 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/11 14:29:47 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
			static const int maxSkills = 4;
			AMateria *_materiaLearned[maxSkills];
	public:
			MateriaSource();
			virtual ~MateriaSource();
			MateriaSource(const MateriaSource &source);
			MateriaSource& operator = (const MateriaSource &source);
			virtual void learnMateria(AMateria*);
			virtual AMateria* createMateria(std::string const & type);
};

#endif //==============MATERIASOURCE_HPP