/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:02:13 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/26 15:51:24 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <string>

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

int dotsCount(std::string input){
	int dotCount = 0;
	size_t pos = input.find('.'); //find the first position
   	while (pos != std::string::npos) {
        dotCount++;
        pos = input.find('.', pos + 1); // Find the next dot position, starting from pos + 1
    }
	return dotCount;
}

bool isValid(std::string input){

	int i = 0;
	if (input.at(0) == '+' || input.at(0) == '-' && !isdigit(input.at(1)))
		return false;
	while (input[i])
	{
		if (!isdigit(input[i]) && input[i] != 'f')
			return false;
		else if (!isdigit(input[i]) && input[i] == 'f' && i != input.length())
			return false;
	}
	return true;
}

int	detecType(std::string input) {
	// detect type char
	//what is char? ascii or only alpha?
	if (input.length() == 1 && isalpha(input[0]))
		return typeChar;

	if (isValid(input) == false)
		return typeError;

	//remember to chck if the input is invalid e.g. 12345abc; ++--245, 0.5ff
	int dotCount = dotsCount(input);
    if (dotCount == 0){
	// detect type int
		int i = std::atoi(input.c_str());
		if (i != 0 || (i == 0 && input[0] == '0'))
			return typeInt;
	}
	else if (dotCount == 1){
	//detect type float
		float f = std::atof(input.c_str());
		if (f != 0.0f || (f == 0.0f && input[0] == '0'))
			return typeFloat;

		//detect type double
		float d = std::atof(input.c_str());
		if (d != 0.0 || (d == 0.0 && input[0] == '0'))
			return typeDouble;
	}

	// If none of the valid types are detected, the input is invalid.
	return typeError;
}

//convert it to a C-style string using c_str()

void Converter::convert(const std::string& input) {
	int type = 0;
	char c = 0;
	int i = 0;
	float f = 0.0;
	double d = 0.0;
	
	type = detecType(input);
	switch (type){
		case typeChar	:
			char c = input[0];
			int i = static_cast<const int>(c);
			float f = static_cast<const float>(c);
			double d = static_cast<const double>(c);
			break;
		case typeInt	:
			int i = std::atoi(input.c_str());
			char c = static_cast<const char>(i);
			float f = static_cast<const float>(i);
			double d = static_cast<const double>(i);
			break;
		case typeFloat	:
			float f = std::atof(input.c_str());
			int i = static_cast<const int>(f);
			char c = static_cast<const char>(f);
			double d = static_cast<const double>(f);
			break;
		case typeDouble	:
			double d = std::atof(input.c_str());
			int i = static_cast<const int>(d);
			char c = static_cast<const char>(d);
			float f = static_cast<const float>(d);
			break;
		case typeError	:
			std::cout << "Invalid input: " << input << std::endl;
			break;
	};
}

/*
detec type
	-parse the input if valid or not vaid
	-check the infinity and nan
convert for evry case

format printing
*/