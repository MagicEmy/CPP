/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/18 13:01:52 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
			std::string	_type;
	public:
			std::string const & getType() const;			void	setType(std::string	type);

			Weapon(std::string	type);
			~Weapon() {}
};

#endif