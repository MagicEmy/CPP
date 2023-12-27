/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 18:36:46 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/27 17:49:24 by emanuela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <list>       	// std::vector
#include <exception>

class NotFound : public std::exception
{
	public: 
			virtual const char* what() const throw() {
				return ("No occurrence is found");
			}
};
			
template <typename T>
typename T::iterator easyfind(T &container, int n){

	auto it = find (container.begin(), container.end(), n);
  	if (it != container.end())
   		return it; // Return iterator if value is found
  	else
    	throw NotFound();
}


#endif

//calculate the index 
//size_t index = std::distance(container.begin(), it);