/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:52:58 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/13 10:33:46 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "idea";
	std::cout 	<< ROSE "Brain " RESET "constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = source._ideas[i];
}

Brain::~Brain()
{
	std::cout 	<< BLUE "Brain " RESET "destructor called" << std::endl;
}

Brain& Brain::operator = (const Brain &source)
{
	if (this == &source) 
		return *this;
		
	for (int i = 0; i < 100; i++)
		_ideas[i] = source._ideas[i];
	return *this;
}

const std::string& Brain::getIdea( int i ) const
{
	if (i >= 0 && i < 99)
		return this->_ideas[i];
	else
		std::cout   << RED "I have space only for 100 ideas. "
					<< "you get idea 0 " <<  RESET << std::endl;
	return this->_ideas[0];
}

void Brain::setIdea(std::string	newIdea, int i)
{
	if (i >= 0 && i < 99)
		this->_ideas[i] = newIdea;
	else
		std::cout   << RED "I have space only for 100 ideas..."
					<< "I'm just an animal brain " <<  RESET << std::endl;
}