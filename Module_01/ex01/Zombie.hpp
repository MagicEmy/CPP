/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:49:15 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/16 18:29:47 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

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