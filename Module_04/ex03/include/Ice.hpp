/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:27 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/29 11:27:26 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
			Ice( void );
			Ice(const Ice &source);
			virtual ~Ice( void );
			Ice & operator = (const Ice &source);
};

#endif //==============ICE_HPP