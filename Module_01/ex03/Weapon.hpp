/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 13:44:24 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
			std::string	_type;
	public:
			std::string const & getType() const;			
			void	setType(std::string	type);

			Weapon(std::string	type);
			~Weapon( void );
};

#endif