/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:22:17 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/07 19:57:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Colors.hpp"
#include <iostream>
#include <string>

class Brain
{
	private:
			std::string _ideas [100];
	public:
			Brain( void );
			Brain(const Brain &source);
			~Brain( void );
			Brain & operator = (const Brain &source);

			const std::string& getIdea( int i) const;
			void  setIdea(std::string newIdea, int i);
};

#endif
