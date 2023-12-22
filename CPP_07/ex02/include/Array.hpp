/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 12:00:56 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/22 19:33:05 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
	
template <typename T>
class Array
{
	private:
	
			size_t _aSize;
			T *_arr;
	public:
			Array( void );
			Array(size_t n);
			
			Array(const Array &src);
			~Array();

			Array &operator =(const Array &src);
			T &operator [](const unsigned int index);

			size_t size( void ) const;
			
			class OutOfBounds : public std::exception
			{
				public:
					virtual const char* what() const throw(){
						return ("index is definitely out of bounds");
					}
			};
			
};

# include "Array.tpp"

#endif

