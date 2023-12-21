/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 17:38:40 by emlicame      #+#    #+#                 */
/*   Updated: 2023/11/29 19:30:01 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <ctime>


//It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base *generate(void){
	
	Base *base;

	switch (std::rand() % 3)
	{
	case 0:
		base = new A;
		break;
	case 1: 
		base = new B;
		break;
	case 2:
		base = new C;
		break;
	}
	return base;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
//the expression dynamic_cast<A*>(p) evaluates to a pointer to an object of type A 
//if the conversion is successful, or nullptr if the conversion fails. 
void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "type of pointer A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type of pointer B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type of pointer C" << std::endl;
	else
		std::cout << "type of pointer unknown" << std::endl;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C"
//dynamic_cast expects a pointer argument
void identify(Base& p){
	try	{
		(void)dynamic_cast<A&>(p);
		std::cout << "type of reference A" << std::endl;
	}
	catch(const std::bad_cast& e) {
		std::cerr << "Failed to cast to type A " << std::endl;
	}
	try	{
		(void)dynamic_cast<B&>(p);
		std::cout << "type of reference B" << std::endl;
	}
	catch(const std::bad_cast& e) {
		std::cerr << "Failed to cast to type B " << std::endl;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "type of reference C" << std::endl;
	}
	catch(const std::bad_cast& e) {
		std::cerr << "Failed to cast to type C " << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Invalid reference type " << e.what() << std::endl;
	}
	//transform to for loop
	
}

int main(void){
	std::srand(time(0));
	for (int i = 0; i < 10; ++i){
		std::cout << "Case " << i << ": \n";
		
		Base *p = generate();
		identify(p);
		identify(*p);
		
		delete p;
	}

	return 0;
}


/*
Fundamental aspect of how dynamic_cast works in C++.
The pointer version returns null on failure, 
while the reference version throws an exception on failure (std::bad_cast)
*/

	/*
	//transform to for loop
	for
	{
		try
		{
			switch
			{
				
			}
		}
		catch
		{
			
		}
	}
	for (int i = 0; ... ;++i)
{
	try
	{
		
	switch (i)
	{
		
	case try	{
		(void)dynamic_cast<A&>(p);
		std::cout << "type of reference A" << std::endl;
	}
	catch(const std::bad_cast& e) {
		std::cerr << "Failed to cast to type A " << std::endl;
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
		break;
	*/