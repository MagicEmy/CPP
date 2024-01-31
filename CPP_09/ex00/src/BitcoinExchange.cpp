#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) {

	try	{
		this->loadDatabase();
		this->parseInputFile(filename);
	}
	catch(const std::exception& e)	{
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

			std::string date = line.substr(0, line.find(',')); // e.g 2022-01-15,43146.53
			dateValidation(date);
			try {
				dateValueMap[date] = std::stof(line.substr(line.find(',') + 1, line.length()));
			} catch(const std::exception& e) {
				throw std::runtime_error("Error: Invalid value " + line.substr(line.find(',') + 1, line.length()));
			}
		}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
		}
	}
	dataFile.close();
}

void BitcoinExchange::dateValidation(std::string& date) {
	
	std::tm tm = {};
	std::stringstream date_ss(date);

	date_ss >> std::get_time(&tm, "%Y-%m-%d"); // "YYYY-MM-DD" format
	if (date_ss.fail()) 
		throw std::runtime_error("Error: Invalid date " + date_ss.str());
}

void BitcoinExchange::parseInputFile(const std::string& filename) {

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
		if (std::strcmp(line.c_str(), "date | value") == 0 || \
			std::strcmp(line.c_str(), "") == 0)
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
	
	float value = 0.0f;
	std::string valueStr;
	
	size_t delimPos = line.find(delim);
	if (delimPos == std::string::npos)
		throw std::runtime_error("Error: Invalid input, invalid format " + line);
	
	std::string date = line.substr(0, delimPos);
	try {
		dateValidation(date);
	}
	catch(const std::exception& e) {
		throw;
	}

	if (delimPos + 1 < line.length()){
		valueStr = line.substr(delimPos + 1, line.length());
		try {
			value = std::stof(valueStr);
		}
		catch(const std::exception& e) {
			throw std::runtime_error("Error: Invalid value " + valueStr);
		}
		
        size_t dotPos = valueStr.find('.');
		if (dotPos != std::string::npos && dotPos + 1 < line.length()) {
			size_t dotPos2 = valueStr.find('.', dotPos + 1);
			if (dotPos != std::string::npos && dotPos2 != std::string::npos)
				throw std::runtime_error("Error: Invalid value " + valueStr);
		}
        if (value < 0 || value > 1000)
            throw std::runtime_error("Error: Invalid value " + valueStr);
        try {
			this->run(date);
			std::cout << date << " => " << value << " = " << value * this->run(date) << std::endl;
		}
		catch(const std::exception& e) {
			throw;
		}

    } else {
        throw std::runtime_error("Error: Invalid input " + valueStr);
    }
}

float BitcoinExchange::run(std::string& date) {

	std::map<std::string, float>::const_iterator it = dateValueMap.lower_bound(date);

    // If 'it' points to the end of _data, return the last element of _data	 
    if (it == dateValueMap.end())
        return (dateValueMap.rbegin()->second);

    // If the date of 'it' is greater than 'date'
    if (it->first > date) {

        // If 'it' points to the beginning of dateValueMap, throw an exception because the date is out of range
        if (it == dateValueMap.begin())
			throw std::runtime_error("Error: invalid date " + date + " first available date: " + dateValueMap.begin()->first);

        // Otherwise, return the rate of the previous day
        return (std::prev(it)->second);
    }

	// If none of the above conditions are met, return the rate of 'it'
	std::cout << "case 5 return (it->second)" << date << std::endl;
    return (it->second);
}
