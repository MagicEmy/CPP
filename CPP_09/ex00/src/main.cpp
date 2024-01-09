#include "BitcoinExchange.hpp"
#include <iostream>

#define MAX 4096
int main (int argc, char **argv)
{
	if ( argc != 2 ) {

		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return (1);
	}

	try {
        BitcoinExchange exchange(argv[1]);
    } catch (const std::runtime_error& e) {
        return 1;
    }

    return 0;

}