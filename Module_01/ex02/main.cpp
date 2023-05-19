/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:45:21 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/17 13:15:03 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main (void)
{
	//A string variable initialized to "HI THIS IS BRAIN"
	std::string brain = "HI THIS IS BRAIN";	
	//stringPTR: A pointer to the string.
	std::string *stringPTR = &brain;
	//stringREF: A reference to the string.
	std::string &stringREF = brain;

	//print memory address of the string variable.
	std::cout << "The memory address of brain is: " << &brain << std::endl;
	//The memory address held by stringPTR.
	std::cout << "The memory address of held by stringPTR: " << stringPTR << std::endl;
	//The memory address held by stringREF.
	std::cout << "The memory address of held by stringREF: " << &stringREF << std::endl;
	
	//print the value of the string variable.
	std::cout << "Value of brain: " << brain << std::endl;
	//print The value pointed to by stringPTR.
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	//The value pointed to by stringREF.
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	return 0;
}

/*
they are like non void constant or always dereferenced pointers
The relevance of a string reference lies in its ability to provide 
an alternative name or alias for an existing string variable. 
It allows you to refer to the same memory location as the original variable, 
without creating a new copy of the string data.

Here are some key points that explain the relevance of a string reference:

Avoiding copy overhead: When you pass a string by value to a function 
or assign it to another variable, a copy of the string data is created. 
This can be inefficient for large strings. 
By using a string reference, you can avoid this copy overhead, 
as the reference simply points to the original string.

Simplifying syntax: References provide a more concise syntax
for accessing and manipulating the original string variable. 
Instead of using pointer dereferencing syntax (*stringPTR) 
or dot operator syntax (str.method()), 
you can directly use the reference as if it were 
the original variable (stringREF.method()).

Readability and clarity: String references can improve the readability and 
clarity of your code. When you encounter a reference in the code, 
it signals that you are working with the original variable and any modifications 
made through the reference will affect the original variable directly. 
This can make the code more understandable for other developers.

Passing arguments to functions: String references are commonly used 
in function parameters to pass strings by reference. 
By using a reference parameter, you can modify the original 
string directly within the function, rather than working with a local copy. 
This is useful when you want the function to modify the string and
 have those modifications reflected in the calling code.

Overall, string references offer a convenient and 
efficient way to work with strings without creating copies or 
modifying the original variable directly. They can improve performance, 
simplify code, and enhance code clarity.*/

/*
if there is a class with an optional member, say a weapon,
I cannot make a reference on that weapon because I should create that weapon,
reference it at the beginning and never change it. 
In this case I would need a pointer 
Using a pointer I would be able to point at somehing that doesn't exist at
the beginning then point on a new weapon, then change a weapon again
*/