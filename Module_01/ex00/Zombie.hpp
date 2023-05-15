/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:36:02 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/13 18:43:51 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombies announce themselves as follows:
// <name>: BraiiiiiiinnnzzzZ...
// es:
// Gigio: BraiiiiiiinnnzzzZ...


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
			void announce( void );
	
	private:
			std::string _name;
};

#endif 		//  ZOMBIE_HPP