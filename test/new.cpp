/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:51:35 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/03 19:14:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <unistd.h>
# include "new.hpp"

Whatever::Whatever()
{
	std::cout << "Colored world!\n";
	this->connection->set_variable(5);
	this->Printy();
}

Whatever::~Whatever()
{
	std::cout << "Back to black\n";	
}

void	Whatever::Printy(void)
{
	std::cout << "Print this modafuccka!\n";	
}

//setter (setters or getters called accessors )
void SecondClass::set_variable(int x)
{
	this->variable = x;
}

int main(void)
{
	int num;
	Whatever thingy;
	std::cin >> num;
	std::cout << "num is" << num;
	return 0;
}
