#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
	private:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void parseFile(const std::string& filename);
		int parseLine(std::string& line);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		~BitcoinExchange();
		void run();

};

#endif // BITCOINEXCHANGE_HPP