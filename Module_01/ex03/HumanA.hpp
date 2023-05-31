/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:14:47 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/24 13:44:40 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
			std::string _name;
			Weapon 		&_weapon;

	public:	
			void attack(void) const;

			HumanA(std::string name, Weapon &weapon);
			~HumanA( void );
};

#endif

/* HumanA will always be armed */