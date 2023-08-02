/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:58:46 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/30 19:32:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( void ) {
}

Converter::Converter(const Converter& src) {
	*this = src;
}

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

	int i = 1;
	if ((input.at(0) == '+' || input.at(0) == '-') && !isdigit(input.at(1)))
		return false;
	else
	{
		while (input[i])
		{
			if (!isdigit(input[i]) && input[i] != 'f' && input[i] != '.')
				return false;
			else if (!isdigit(input[i]) && input[i] == 'f' && input[i + 1] != '\0')
				return false;
			i++;
		}
	}
	return true;
}

bool isPseudo(const std::string& input) {
	if (input == "+inf" || input == "-inf" || input == "nan" || \
	input == "+inff" || input == "-inff" || input == "nanf")
		return true;
	return false;
}
int	detecType(const std::string& input) {

	if (input.length() == 1 && isalpha(input[0]))
		return typeChar;
	if (!std::isprint(input.at(0))) {
    	std::cerr << "Non-displayable character in literal: " << input << std::endl;
	    return typeError;
	}
	if (isValid(input) == false)
		return typeError;
	
	if(isPseudo(input))
		return typePseudo;
	int dotCount = dotsCount(input);
    if (dotCount == 0){
		try {
            // Attempt to convert to int
            std::stoi(input);
            return typeInt;
        } catch (const std::invalid_argument&) {
        } catch (const std::out_of_range&) {
        }
	}
	else if (dotCount == 1 && input.at(input.length() - 1) != 'f'){
		try {
            // Attempt to convert to double
            std::stod(input);
            return typeDouble;
        } catch (const std::invalid_argument&) {
        } catch (const std::out_of_range&) {
        }
	}
	else if (dotCount == 1 && input.at(input.length() - 1) == 'f'){
		try {
            // Attempt to convert to float
           	std::stof(input);
            return typeFloat;
        } catch (const std::invalid_argument&) {
        } catch (const std::out_of_range&) {
        }
	}
	// If none of the valid types are detected, the input is invalid.
	return typeError;
}

void Converter::convert(const std::string& input) 
{
	char c;
	int i;
	float f;
	double d;
	
	int type = detecType(input);
	switch (type){
		case typeChar	:
			c = input.at(0);
			std::cout << "Char : " << c << "\n";
			std::cout << "Int : " << static_cast<const int>(c) << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Float : " << static_cast<const float>(c) << "f" << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Double : " << static_cast<const double>(c) << std::endl;
			break;
		case typeInt	:
			i = std::stoi(input);
			if (i >= 0 && i <= 39)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "Char : " << static_cast<const char>(i) << "\n";
			std::cout << "Int : " << i << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Float : " << static_cast<const float>(i) << "f" << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Double : " << static_cast<const double>(i) << std::endl;
			break;
		case typeFloat	:
			f = std::stof(input);
			std::cout << f << "\n";
			if (f >= 0 && f <= 39)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "Char : " << static_cast<const char>(f) << "\n";
			std::cout << "Int : " << static_cast<const int>(f) << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Float : " << f << "f" << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Double : " << static_cast<const double>(f) << std::endl;
			break;
		case typeDouble	:
			d = std::stod(input);
			if (d >= 0 && d <= 39)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "Char : " << static_cast<const char>(d) << "\n";
			std::cout << "Int : " << static_cast<const int>(d) << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Float : " << static_cast<const float>(d) << "f" << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Double : " << d << std::endl;
			break;
		case typePseudo :
			std::cout << "Char : impossible conversion\n";
			std::cout << "Int : impossible conversion\n";
			std::cout << std::fixed << std::setprecision(1) << "Float : " << std::stof(input) << "f" << "\n";
			std::cout << std::fixed << std::setprecision(1) << "Double : " << std::stod(input) << std::endl;
			break;
		case typeError	:
			std::cout << "Invalid input: " << input << std::endl;
			break;
	};
}
