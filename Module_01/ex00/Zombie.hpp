/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:36:02 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 15:37:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


class Zombie
{
	private:
			std::string _name;
			
	public:
			void announce( void );
			
			Zombie(std::string name);
			~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif 		//  ZOMBIE_HPP
