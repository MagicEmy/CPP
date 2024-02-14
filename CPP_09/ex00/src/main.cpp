#include "BitcoinExchange.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	if ( argc != 2 ) {

		std::cout << "Usage: ./bitcoin [input file]" << std::endl;
		return (1);
	}

	try {
        BitcoinExchange exchange(argv[1]);
    } catch (const std::runtime_error& e) {
        return 1;
    }

    return 0;

}