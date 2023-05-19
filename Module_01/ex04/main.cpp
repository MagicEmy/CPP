/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:38:14 by emlicame          #+#    #+#             */
/*   Updated: 2023/05/19 19:10:28 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>

void replaceOccurrence(const std::string& filename, std::string &s1, std::string s2)
{
	std::ifstream	inFile(filename);
	std::ofstream	outFile(filename + ".replace");
	std::string line;
	
	if (inFile.is_open() && outFile.is_open())
	{
		while (std::getline(inFile, line))
		{
			size_t pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
                pos += s2.length();				
			}
			outFile << line << "\n";
		}
		inFile.close();
		outFile.close();
	}
	else
		std::cout << "Error. Failed to open the input or output file" <<std::endl;
}

int	main(int argc, char **argv)
{
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	if (argc != 4)
	{
		std::cout << "Enter name of file to read, 1 word to be found and 1 word that will replace the previous one" 
				  << std::endl;
		return 1;
	}
	replaceOccurrence(filename, s1, s2);
	return (0);
}
