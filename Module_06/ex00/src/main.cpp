/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:10 by emlicame          #+#    #+#             */
/*   Updated: 2023/07/30 18:22:47 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <string>

int main(int argc, char** argv) {

	if (argc != 2){
		std::cout << "Wrong input, please enter a string with a valid literal" << std::endl;
		return 0;
	}
	std::string input = argv[1];
	if (input.empty()){
		std::cout << "Error: empty string" << std::endl;
		return 0;
	}
    Converter::convert(input);
    return 0;
}
