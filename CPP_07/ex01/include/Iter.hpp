/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 12:11:09 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/20 20:20:28 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cctype>

template <typename T>
void func(T &x)
{
	std::cout << x << " ";
}


template <typename T>
void	toUpper(T &c)
{
	c = std::toupper(c);
}


template <typename T>
void iter(T *arr, size_t aSize, void (*f)(T &val))
{
	if (!arr)
		return;
	for (size_t i = 0; i < aSize; ++i)
		f(arr[i]);
}

#endif