/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:53:49 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/05 19:55:06 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contacts.hpp"


# define C_LVIOLET	"\x1b[38;2;192;0;255m"
# define C_DBLUE	"\x1b[38;2;0;0;128m"
# define C_DMGNT	"\x1b[38;2;128;0;128m"
# define C_DRED		"\x1b[38;2;128;0;0m"
# define C_RESET	"\x1b[0m"

# define MAX 8

class PhoneBook
{
	private:
			Contacts	Contacts[8];
			static int	index;
			
	public:
	
			PhoneBook(void);
			~PhoneBook(void);

			// void		startSession(void);
			void	addContacts(void);
			void	searchContacts(void);
			void	displayContacts(void);
};

#endif