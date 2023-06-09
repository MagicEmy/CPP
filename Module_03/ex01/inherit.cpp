/*
Inheritance is a fundamental concept in object-oriented programming (OOP) that 
allows you to create new classes (derived classes) based on existing classes
(base classes). 
The derived classes inherit the properties and behaviors of the base class, 
allowing for code reuse and creating a hierarchical relationship between classes.

In C++, you can define inheritance using the class or struct keyword, 
followed by a colon (:), and then the access specifier 
(public, protected, or private) followed by the base class name. 
Here's the syntax:

class BaseClass
{
    // Base class members...
};

class DerivedClass : access-specifier BaseClass
{
    // Derived class members...
};
*/

#include <iostream>
#include <string>

// Base class
class Animal
{
protected:
    std::string _name;

public:
    Animal(const std::string& name)
        : _name(name)
    {
    }

    void eat()
    {
        std::cout << _name << " is eating." << std::endl;
    }

    void sleep()
    {
        std::cout << _name << " is sleeping." << std::endl;
    }
};

// Derived class
class Dog : public Animal
{
public:
    Dog(const std::string& name)
        : Animal(name)
    {
    }

    void bark()
    {
        std::cout << _name << " is barking." << std::endl;
    }
};

int main()
{
    // Create an instance of the derived class
    Dog dog("Buddy");

    // Access base class methods
    dog.eat();
    dog.sleep();

    // Access derived class method
    dog.bark();

    return 0;
}

/*
In the above example, we have a base class Animal and a derived class Dog. 
The derived class Dog inherits from the base class Animal using the public
access specifier.

The base class Animal has a protected member variable _name and two 
member functions eat() and sleep(). The derived class Dog adds a 
new member function bark().

In the main() function, we create an instance of the derived class Dog 
called dog. We can access the base class methods eat() and sleep() 
directly through the dog object. Additionally, we can access the derived
class method bark().

The derived class Dog inherits the member variable _name and the member 
functions eat() and sleep() from the base class Animal. 
This allows us to reuse the existing functionality defined in the base class 
and extend it with additional functionality specific to the derived class.

Inheritance allows for code reuse, modularity, and the ability to create 
class hierarchies. It forms the basis for more advanced concepts 
such as polymorphism and virtual functions, 
which enable dynamic binding and runtime polymorphism.
*/