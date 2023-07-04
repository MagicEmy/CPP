/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:42:32 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/03 13:16:44 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap(std::string name);
		FragTrap(const FragTrap &source);
		~FragTrap( void );
		FragTrap & operator = (const FragTrap &source);

		void highFivesGuys( void );
};

#endif