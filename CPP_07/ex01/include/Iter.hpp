/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 12:11:09 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/22 19:32:04 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cctype>

template <typename T>
void	toUpper(T &c)
{
	c = std::toupper(c);
	std::cout << c << " ";
}


template <typename T>
void func(T const &x)
{
	std::cout << x << " ";
}


template <typename T>
void iter(T *arr, size_t aSize, void(*f)(T const &val))
{
	if (!arr)
		return;
	for (size_t i = 0; i < aSize; ++i)
		f(arr[i]);
}

template <typename T>
void iter(T *arr, size_t aSize, void(*f)(T &val))
{
	if (!arr || !f)
		return;
	for (size_t i = 0; i < aSize; ++i)
		f(arr[i]);
}

#endif





/*

The function iter is overloaded based on the type of the third argument, 
which is a function pointer. The distinction lies in the function pointer's type signature, 
not in the const qualifier of the parameter.
*/