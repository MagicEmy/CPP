/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Converter.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/30 14:58:46 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/21 14:15:54 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <limits>

Converter::Converter( void ) {}

Converter::Converter(const Converter& src) { *this = src; }

Converter::~Converter( void ) {}

Converter& Converter::operator =(const Converter& src){
	if (this == &src)
		return (*this);
	return (*this);
}

int dotsCount(const std::string& input){
	int dotCount = 0;
	size_t pos = input.find('.'); //find the first position
   	while (pos != std::string::npos) {
        dotCount++;
        pos = input.find('.', pos + 1); // Find the next dot position, starting from pos + 1
    }
	return dotCount;
}

bool isValid(const std::string& input){

	size_t i = 0;
	if ((input.at(i) == '+' || input.at(i) == '-') && std::isdigit(input.at(i + 1)))
		i++;
	if (input.at(i) == '.')
		return false;
	for (; i <= input.size() - 1; ++i){
		if (!std::isdigit(input.at(i)) && input.at(i) != '.'){
			if (input.at(i) == 'f' && i == input.size() - 1)
				return true;
			return false;
		}
	}
	return true;
}

bool isPseudo(const std::string& input) {
	std::string		pseudos[] = {"-inff", "+inff", "inff", "nanf", "-inf", "+inf", "inf", "nan"};
	const int numPseudos = sizeof(pseudos) / sizeof(pseudos[0]);
	for (int i = 0; i < numPseudos; i++){
		if (input == pseudos[i])
			return true;
	}
	return false;
}

int	detecType(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input.at(0)) && std::isprint(input.at(0)))
		return TYPE_CHAR;
	if (!std::isprint(input.at(0))) {
    	std::cerr << "Non-displayable character in literal: " << input << std::endl;
	    return TYPE_ERROR;
	}
	if(isPseudo(input))
		return TYPE_PSEUDO;
	int dotCount = dotsCount(input);
	if (dotCount != 0 && dotCount != 1)
		return TYPE_ERROR;
	if (isValid(input) == false)
		return TYPE_ERROR;

	if (dotCount == 0){
	try {
		// Check validity of input as integer
		std::stoi(input);
		return TYPE_INT;
	} catch (std::out_of_range &e) {}}
	if (input.at(input.length() - 1) == 'f'){
		try {
			// Check validity of input as float
			std::stof(input);
			return TYPE_FLOAT;
		} catch (std::exception &e) {}
	} else {
		try {
			// Check validity of input as double
			std::stod(input);
			return TYPE_DOUBLE;
		} catch (std::exception &e) {}
	}

	return TYPE_ERROR;
}

void printChar(int i){
	if (i < 0 || i > 126)
		std::cout << "Char : Invalid" << std::endl;
	else if (!isprint(i))
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char : '" << static_cast<char>(i) << "'" << std::endl;
}

void printInteger(float f, bool valf, double d, bool vald){
	if (valf == true ){
		if (f < static_cast<float>(std::numeric_limits<int>::min()) || \
			f > static_cast<float>(std::numeric_limits<int>::max())	)
    		std::cout << "Int : Out of range" << std::endl;
		else
			std::cout << "Int : " << static_cast<int>(f) << std::endl;
	}
	else if (vald == true ){
		if (d < static_cast<double>(std::numeric_limits<int>::min()) || \
			d > static_cast<double>(std::numeric_limits<int>::max()) )
    		std::cout << "Int : Out of range" << std::endl;
		else
			std::cout << "Int : " << static_cast<int>(d) << std::endl;
	}		
}

void printFloatDouble(float f, double d){
	std::cout 	<< std::fixed << std::setprecision(1) 
				<< "Float : " << f << "f" << "\n"
				<< "Double : " << d << std::endl;
}

// 2147483647
void Converter::convert(const std::string& input) 
{
	char c;
	int i;
	float f;
	double d;
	
	int type = detecType(input);
	
	switch (type){
		case TYPE_CHAR	:
			c = input.at(0);
			printChar(c);
			std::cout << "Int : " << static_cast<int>(c) << std::endl;
			printFloatDouble(static_cast<float>(c), static_cast<double>(c));
			break;
		case TYPE_INT	:
			i = std::stoi(input);
			printChar(i);
			std::cout << "Int : " << i << std::endl;
			printFloatDouble(static_cast<float>(i), static_cast<double>(i));
			break;
		case TYPE_FLOAT	:
			f = std::stof(input);
			printChar(static_cast<int>(f));
			printInteger(f, true, 0.0, false);
			printFloatDouble(f, static_cast<double>(f));
			break;
		case TYPE_DOUBLE	:
			d = std::stod(input);
			printChar(static_cast<int>(d));
			printInteger(0.0, false, d, true);
			printFloatDouble(static_cast<float>(d), d);
			break;
		case TYPE_PSEUDO :
			std::cout << "Char : impossible conversion\n";
			std::cout << "Int : impossible conversion\n";
			printFloatDouble(std::stof(input), std::stod(input));
			break;
		case TYPE_ERROR	:
			std::cout << "Invalid input: " << input << std::endl;
			break;
	};
}



//include const if you don't intend to modify the result e.g. static_cast<const float>(i)