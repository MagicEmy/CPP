/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:52:12 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/11 13:14:45 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

// Forward declaration of ICharacter class to resolve circular dependency
class ICharacter;

#include "ICharacter.hpp" // Include ICharacter.hpp after forward declaration


class AMateria
{
	protected:
			std::string _AMateriaType;
	public:
			AMateria();
			AMateria(std::string const & type);
			AMateria(const AMateria &source);
			virtual ~AMateria( void );
			AMateria & operator = (const AMateria &source);

			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
};

#endif		//==============AMATERIA_HPP		


/*
there is a circular dependency between the AMateria.hpp and ICharacter.hpp files. 
Each file includes the other, which can lead to compilation issues.

To resolve this circular dependency, you can use forward 
declarations in the header files. Here's how you can modify the code:

In AMateria.hpp:

#pragma once

#include <string>

// Forward declaration of ICharacter class
class ICharacter;

class AMateria
{
    // ... rest of your code ...
    virtual void use(ICharacter& target);
};
In ICharacter.hpp:
#pragma once

#include <string>

// Forward declaration of AMateria class
class AMateria;

class ICharacter
{
    // ... rest of your code ...
    virtual void use(int idx, ICharacter& target) = 0;
};
By using forward declarations, the compiler will know that both classes exist 
without needing to include their respective headers. 
This resolves the circular dependency issue.

Make sure to update any other files that include 
these headers to avoid potential compilation errors.

Note: When forward declaring a class, you can only use pointers 
or references to that class in the header where the forward declaration is made. 
The full definition of the class should be included in the 
corresponding source file where it is used.

The #pragma once directive is a non-standard but widely supported feature in C++ compilers. 
It is a compiler-specific directive used as a header guard to prevent 
multiple inclusions of the same header file within a translation unit (source file).

When #pragma once is added at the beginning of a header file, 
the compiler will ensure that the file is only included once during the compilation process, 
regardless of how many times it is referenced or included by other files. 
This eliminates the need for traditional header guards 
(#ifndef, #define, and #endif) to prevent multiple inclusions.

Using #pragma once provides a cleaner and more concise way to avoid 
include duplication and potential issues caused by circular dependencies. 
It improves compilation time by reducing the need to reprocess the same header file multiple times.

example
#pragma once

// Header file contents...

Note that although #pragma once is widely supported and commonly used, it is not part of the C++ standard. 
Therefore, it may not work with every compiler. 
However, it is supported by most major compilers, including GCC, Clang, and Visual C++.
*/