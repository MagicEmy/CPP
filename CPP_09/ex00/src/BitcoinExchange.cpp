#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() {

	std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {

	std::cout << "BitcoinExchange constructor called" << std::endl;
	this->parseFile(filename);
}	

BitcoinExchange::~BitcoinExchange() {
	//clear map
	std::cout << "BitcoinExchange destructor called" << std::endl;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {

	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {

	if (this != &other) {
		// Do stuff
	}
	return (*this);
}

void BitcoinExchange::parseFile(const std::string& filename) {

	std::ifstream inFile(filename);

	if (!inFile) {
		std::cout << "Error: Can't open file" << std::endl;
		throw std::runtime_error("Can't open file");
	}

	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();
	if (size == 0) {
		std::cout << "Error: File is empty" << std::endl;
		throw std::runtime_error("File is empty");
	}
	inFile.seekg(0, std::ios::beg);
	std::string line;
	while (std::getline(inFile, line)) {
		if (!this->parseLine(line)) {
			throw std::runtime_error("Invalid line");
		}
	}
	inFile.close();
}

int BitcoinExchange::parseLine(std::string& line) {

		std::stringstream ss(line);
		std::string date, valueStr;
		std::getline(ss, date, '|');
		std::getline(ss, valueStr);
		float value = std::stof(valueStr);

		if (value < 0 || value > 1000) {
			std::cout << "Error: Invalid value in line - " << line << std::endl;
			return 0;
		}
		return 1;
}

void BitcoinExchange::run() {

	std::cout << "BitcoinExchange run method called" << std::endl;
}


/*

read the file line by line
parse each line

if file is not well formated, throw exception

fill the map with the data from the file
check if the line is well formated
if not, throw exception
	if yes, parse the line
		check if the date is already in the map
			if yes, add the value to the existing one
			if no, add the date and the value to the map


only digits and dots are allowed in the price
only digits are allowed in the date
only positive numbers are allowed in the quantity
valid price format: 0.0 (float or integer)
valid date format: YYYY-MM-DD
valid quantity format: 0
valid range for quantity: 0-1000

if the date is already in the map, add the value to the existing one
if the date is not in the map, add the date and the value to the map

if parsing ok

date | value
2011-01-03 | 3

Output:
2011-01-03 => 3 = 0.9
date | value => quantity = price

*/
