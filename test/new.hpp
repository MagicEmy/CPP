/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:20:16 by emlicame          #+#    #+#             */
/*   Updated: 2023/04/07 17:00:57 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW
# define NEW

class Whatever
{
	public:
	
	Whatever();
	~Whatever();

	private:
	
	class SecondClass *connection;
	void Printy();
};

class SecondClass
{
	public:

	SecondClass();
	~SecondClass();
	
	void set_variable(int);

	private:

	int variable;
};

#endif