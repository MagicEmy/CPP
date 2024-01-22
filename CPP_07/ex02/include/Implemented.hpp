/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: emanuela <emanuela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 12:59:36 by emanuela      #+#    #+#                 */
/*   Updated: 2023/12/22 11:57:16 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// #ifndef ARRAY_HPP
// #define ARRAY_HPP

// #include <iostream>
// #include <exception>
	
// template <typename T>
// class Array
// {
// 	private:
	
// 			size_t _aSize;
// 			T *_arr;
// 	public:
// 			Array( void ) : _aSize(0), _arr(nullptr) {}
// 			Array(size_t n) : _aSize(n), _arr(new T[_aSize]) {}
			
// 			Array(const Array &src) : _aSize(src._aSize), _arr(new T[_aSize]) {
// 				*this = src;
// 			}
			
// 			Array &operator =(const Array &src){
// 				if (this == &src)
// 					return *this;
// 				delete [] this->_arr;
// 				this->_aSize = src._aSize;
// 				this->_arr = new T[_aSize];
// 				for (size_t i = 0; i < _aSize; ++i){
// 					this->_arr[i] = src._arr[i];
// 				}
// 				return *this;
// 			}
			
// 			class OutOfBounds : public std::exception
// 			{
// 				public:
// 					virtual const char* what() const throw(){
// 						return ("index is out of bounds");
// 					}
// 			};
			
// 			T &operator [](const unsigned int index){
// 				if (index >= _aSize)
// 					throw OutOfBounds();
// 				return _arr[index];
// 			}
			
// 			~Array(){
// 				delete [] _arr;
// 			}

// 			size_t size( void ) const{
// 				return _aSize;
// 			}
// };


// #endif