/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 11:29:17 by emlicame      #+#    #+#                 */
/*   Updated: 2024/01/02 17:08:36 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
	private:
			// can store a maximum of N integers
			unsigned int _maxSize;

	public:
			Span();
			Span(int n);
			Span(const Span &src);
			Span &operator =(const Span &src);
			~Span();
			
			std::vector<int> _spanVec;
			void addNumber(int n);
			void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
			void fillRangeInSpan(int start, int end);
			int shortestSpan( void );
			int longestSpan( void );
			
			class ContainerFull : public std::exception {
				public:
						virtual const char *what() const throw();
			};
			
			class NoElements : public std::exception {
				public:
						virtual const char *what() const throw();
			};
			
			class WrongRange : public std::exception {
				public:
						virtual const char *what() const throw();
			};

};

/*
n this example, the insert function is taking a range of iterators (newElements.begin() and newElements.end()) 
to add a sequence of elements from newElements into myVector starting at the specified position.

Understanding and utilizing ranges of iterators in functions like insert helps in efficiently manipulating 
sequences of elements in containers in C++.
*/

#endif	// SPAN_HPP