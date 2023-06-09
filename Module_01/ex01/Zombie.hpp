/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:49:15 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 18:55:20 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#define RED		"\x1b[38;2;255;0;0m"
#define GREEN	"\x1b[38;2;0;255;0m"
#define ORANGE	"\x1b[38;2;255;128;0m"
#define YELLOW	"\x1b[38;2;255;255;0m"
#define CYAN	"\x1b[38;2;0;255;255m"
#define BLUE	"\033[34m"
#define MGNT	"\x1b[38;2;255;0;255m"
#define RESET	"\033[0m"

class Zombie
{
	private:
			std::string _name;
			static int _index;
			
	public:
			void announce( void );
			void setName( std::string name);

			int indexName;
			
			Zombie();
			~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif //------------MOARBRAINZ_HPP