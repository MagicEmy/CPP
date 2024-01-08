#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <filesystem>

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