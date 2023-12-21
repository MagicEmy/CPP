/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 18:23:10 by emlicame      #+#    #+#                 */
/*   Updated: 2023/11/22 13:31:10 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main( void ) {

	Data data = {10, ""};
    Data* ptr = &data;

    uintptr_t serialized = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(serialized);

    if (ptr == deserialized) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
	
    return 0;
}

/*

+ Pointer Types:
Pointer to Pointer: 
You can use reinterpret_cast to cast between different pointer types. 
For example, casting from a pointer to an int to a pointer to a double.

// Casting between pointers
int* intPtr = new int(42);
double* doublePtr = reinterpret_cast<double*>(intPtr);

Pointer to Integer: 
You can cast a pointer to an integer type, 
such as uintptr_t for storing memory addresses.

// Casting a pointer to an integer (uintptr_t)
uintptr_t uintptr = reinterpret_cast<uintptr_t>(intPtr);

Pointer to Void Pointer (void*): 
This is often used to convert between different pointer types in a more generic way.

// Casting a pointer to a void pointer (void*)
void* voidPtr = reinterpret_cast<void*>(intPtr);

++ Reference Types:
Reference to Reference: 
You can cast one reference type to another. 
For example, casting a reference to a base class to a reference 
to a derived class (upcasting or downcasting).

// Casting between references
BaseClass& baseRef = someDerivedClassObject;
DerivedClass& derivedRef = reinterpret_cast<DerivedClass&>(baseRef);

+++ Function Pointers:
Function Pointer to Function Pointer: 
You can use reinterpret_cast to cast between different function pointer types.

// Casting between function pointers
using FunctionPtrType = void(*)(int);
FunctionPtrType functionPtr = reinterpret_cast<FunctionPtrType>(&someFunction);

*/

