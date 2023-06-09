/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:24:29 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:09:30 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
			std::string _name;
			Weapon		*_weapon;

	public:	
			void attack() const;
			void setWeapon(Weapon &Weapon);

			HumanB(std::string name);
			~HumanB(void);
};

#endif
