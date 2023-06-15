/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:38:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/06/15 10:52:46 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceOccurrence(const std::string& filename, std::string &s1, std::string s2)
{
	std::ifstream	inFile(filename);
	
	if (!inFile.is_open())  //check if infile exists and has permissions
	{
		std::cout << "Error. Failed to open the input" <<std::endl;
		return ;
	}
	std::ofstream	outFile(filename + "-replacement");
	
	if (!outFile.is_open()) //check if outfile exists and has permissions
	{
		std::cout << "Error. Failed to open the output file" <<std::endl;
		return ;
	}

    std::stringstream buffer;
    buffer << inFile.rdbuf(); // read entire contents of file into buffer

    std::string line = buffer.str();

	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) // loop through line until end
	{
		line.erase(pos, s1.length());						// erase the old string.
		line.insert(pos, s2);								// insert the new string.
		pos += s2.length();									//update the new position with the length of the new string
	}
	outFile << line;
	
	outFile.close();
	inFile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Enter the name of file to read, 1 word to be replaced and 1 word as replacement\n" 
				  << "example: ./Sed <infile> <hello> <ciao>"
				  << std::endl;
		return 1;
	}

	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	if (!s1.length())
	{
		std::cout << "the word or character to find, cannot be empty" << std::endl;
		return 1;
	}
	std::string		s2 = argv[3];
	
	replaceOccurrence(filename, s1, s2);
	return (0);
}
