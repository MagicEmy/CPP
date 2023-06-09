/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:38:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/09 19:31:13 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#define RED		"\x1b[38;2;255;0;0m"
#define DRED	"\x1b[38;2;128;0;0m"
#define GREEN	"\x1b[38;2;0;255;0m"
#define ORANGE	"\x1b[38;2;255;128;0m"
#define YELLOW	"\x1b[38;2;255;255;0m"
#define CYAN	"\x1b[38;2;0;255;255m"
#define BLUE	"\033[34m"
#define MGNT	"\x1b[38;2;255;0;255m"
#define DMGNT	"\x1b[38;2;128;0;128m"
#define RESET	"\033[0m"

class Harl
{
	private:
			std::string levelsOn[4];
			void debug( void );
			void info( void );
			void warning( void );
			void error( void );

	public:
			void complain( std::string level );
			
			Harl(void);
			~Harl(void);
};

#endif //-----------HARL_HPP