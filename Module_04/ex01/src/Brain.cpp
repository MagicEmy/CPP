/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/21 13:02:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea";
	std::cout 	<< ROSE "Brain constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &source)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = source._ideas[i];
}

Brain::~Brain()
{
	std::cout 	<< DMGNT "Brain distructor called" RESET << std::endl;
}

Brain& Brain::operator = (const Brain &source)
{
	if (this == &source) 
		return *this;
		
	for (int i = 0; i < 100; i++)
		_ideas[i] = source.getIdea(i);
	return *this;
}

const std::string& Brain::getIdea( int i ) const
{
	return _ideas[i];
}

void Brain::setIdea(std::string	newIdea, int i)
{
	if (i >= 0 && i < 99)
		this->_ideas[i] = newIdea;
	else
		std::cout   << RED "I have space only for 100 ideas. I'm too small for extra ideas..."
					<< "I'm just an animal brain " <<  RESET << std::endl;
}
			