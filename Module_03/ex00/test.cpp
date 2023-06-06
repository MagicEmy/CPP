#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    // Constructor
    ClapTrap(const std::string& newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap constructor called. Name: " << name << std::endl;
    }

    // Destructor
    ~ClapTrap() {
        std::cout << "ClapTrap destructor called. Name: " << name << std::endl;
    }

    // Member function to attack a target
    void attack(const std::string& target) {
        if (hitPoints <= 0 || energyPoints <= 0) {
            std::cout << "ClapTrap " << name << " can't perform the attack. It has no hit points or energy points left.\n";
            return;
        }

        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    }

    // Member function to take damage
    void takeDamage(unsigned int amount) {
        if (hitPoints <= 0) {
            std::cout << "ClapTrap " << name << " is already destroyed. It cannot take any more damage.\n";
            return;
        }

        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage.\n";

        if (hitPoints <= 0) {
            hitPoints = 0;
            std::cout << "ClapTrap " << name << " has been destroyed!\n";
        }
    }

    // Member function to repair ClapTrap
    void beRepaired(unsigned int amount) {
        if (hitPoints <= 0) {
            std::cout << "ClapTrap " << name << " is destroyed. It cannot be repaired.\n";
            return;
        }

        hitPoints += amount;
        std::cout << "ClapTrap " << name << " is repaired and gains " << amount << " hit points.\n";
    }
};

/*
n this code, the ClapTrap class is defined with private attributes name, 
hitPoints, energyPoints, and attackDamage. 
The constructor initializes the name attribute using the provided parameter 
and sets the other attributes to their default values.

The attack member function checks if the ClapTrap has enough hit points 
and energy points to perform the attack. 
If it does, it decreases the energy points by 1 and outputs 
a message indicating the attack.

The takeDamage member function deducts the specified amount of hit points 
from the ClapTrap's hit points. 
It also checks if the ClapTrap has already been destroyed and handles 
the destruction accordingly.

The beRepaired member function adds the specified amount of hit points 
to the ClapTrap's hit points. 
It checks if the ClapTrap is already destroyed and handles the repair accordingly.
*/