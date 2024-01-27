#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> dateValueMap; // Map to store date and value
		
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		void parseInputFile(const std::string& filename);
		void parseLine(std::string& line, char delim);
		float run(std::string& date);
		void loadDatabase();
		void dateValidation(std::string& date);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		~BitcoinExchange();

};

#endif // BITCOINEXCHANGE_HPP