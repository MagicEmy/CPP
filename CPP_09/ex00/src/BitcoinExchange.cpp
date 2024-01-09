#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) {

	try
	{
		this->loadDatabase();
		this->parseFile(filename);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {

	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {

	if (this != &src) {
		this->dateValueMap = src.dateValueMap;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {

	dateValueMap.clear();
}

void BitcoinExchange::loadDatabase() {

	std::ifstream dataFile("data.csv");

	if (!dataFile) {
		std::cout << "Error: Can't open file" << std::endl;
		throw std::runtime_error("Can't open file");
	}

	dataFile.seekg(0, std::ios::end);
	size_t size = dataFile.tellg();
	if (size == 0) {
		std::cout << "Error: File is empty" << std::endl;
		throw std::runtime_error("File is empty");
	}
	dataFile.seekg(0, std::ios::beg);
	std::string line;
	while (std::getline(dataFile, line)) {
		if (std::strcmp(line.c_str(), "date,exchange_rate") == 0)
			continue;

		try	{
			parseLine(line, ',');
			std::string date = line.substr(0, line.find(',')); // e.g 2022-01-15,43146.53
			dateValueMap[date] = std::stof(line.substr(line.find(',') + 1, line.length()));			
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	dataFile.close();
}



void BitcoinExchange::parseFile(const std::string& filename) {

	std::ifstream inFile(filename);

	if (!inFile) 
		throw std::runtime_error("Can't open file");

	inFile.seekg(0, std::ios::end);
	size_t size = inFile.tellg();
	if (size == 0)
		throw std::runtime_error("File is empty");
	
	inFile.seekg(0, std::ios::beg);
	std::string line;
	while (std::getline(inFile, line)) {
		if (std::strcmp(line.c_str(), "date | value") == 0)
			continue;
		try	{
			parseLine(line, '|');
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	inFile.close();
}

void BitcoinExchange::parseLine(std::string& line, char delim ) {

		std::stringstream ss(line);
		std::string date = "";
		float value = 0.0f;
		ss >> date >> delim >> value;
		
		// Date validation
		std::tm tm = {};
		std::stringstream date_ss(date);

		date_ss >> std::get_time(&tm, "%Y-%m-%d"); // "YYYY-MM-DD" format
		if (date_ss.fail()) 
			throw std::runtime_error("Error: Invalid date " + date_ss.str());

		//Value validation
		if (value < 0 || value > 1000)
			throw std::runtime_error("Error: Invalid value " + std::to_string(static_cast<int>(value)));
		if (delim == '|')
			std::cout << date << " => " << value << " = " << value * this->run(date) << std::endl;
		
}

float BitcoinExchange::run(std::string& date) {

	std::map<std::string, float>::const_iterator it = dateValueMap.lower_bound(date);

    // If 'it' points to the end of _data, return the last element in _data
    if (it == dateValueMap.end())
        return (dateValueMap.rbegin()->second);

    // If the date of 'it' is greater than 'date'
    if (it->first > date) {
        // If 'it' points to the beginning of dateValueMap, return its rate
        if (it == dateValueMap.begin())
            return (it->second);
        // Otherwise, return the rate of the previous day
        return (std::prev(it)->second);
    }
	// If none of the above conditions are met, return the rate of 'it'
    return (it->second);
}



// std::map<std::string, float>::iterator begin = this->dateValueMap.begin();
// std::map<std::string, float>::iterator end = this->dateValueMap.end();
// for (std::map<std::string, float>::iterator it = begin; it != end; ++it) {
// 	std::cout << it->first << " => " << it->second << '\n';
// }
// std::cout << dateValueMap.size() << std::endl;
// }

