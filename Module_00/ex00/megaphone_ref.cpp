/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone_ref.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:11:20 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/22 12:34:51 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cctype>

//range-based for loop is a C++11 extension [-Werror,-Wc++11-extensions]
 //      for (char& c : str)
std::string	capitalize(std::string str)
{
	for (char& c : str)
    {
        c = std::toupper(c);
    }
    return str;
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv[i])
		std::cout << capitalize(argv[i++]) << " ";
	std::cout << std::endl;
	return 0;
}

/*
use char& to directly modify each character in the string.

char& is a reference to a character type. 
In C++, a reference is an alias for an existing object. 
When we declare a reference to a character (char& c), 
it means that c is an alternative name for an existing character object.

In the context of the code, char& c : str is a range-based for loop 
that iterates over each character (c) in the str string. 
By using a reference, we can directly modify the characters 
in the string within the loop body.

Here's how it works:

char& c declares a reference variable c of type char.
: str specifies the range or container to iterate over, 
which is the str string.
Within the loop body, any modifications made to c will affect 
the corresponding character in the str string.
Using a reference in this case avoids creating a copy 
of each character in the string, resulting in better 
performance and efficiency compared to using an index-based
loop with a copy of the character.

for (char& c : str)
{
    c = std::toupper(c);
}
*/