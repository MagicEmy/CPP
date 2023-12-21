/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 11:56:31 by emanuela      #+#    #+#                 */
/*   Updated: 2023/11/28 18:14:59 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(T &x, T &y)
{
	if (x < y)
		return x;
	return y;
}

template <typename T>
T max(T &x, T &y)
{
	if (x > y)
		return x;
	return y;
}

#endif