/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:58 by jchene            #+#    #+#             */
/*   Updated: 2022/10/05 18:45:07 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

int exitError(const char *str)
{
	std::cout << str << std::endl;
	return (-1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (exitError("Bad number of arguments"));

	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		infileName = argv[1];
	std::string		outfileName = infileName + ".replace";

	inputFile.open(infileName.c_str(), std::ios::in);
	if (!inputFile.is_open())
		return (exitError("Input file can not be opened"));
	outputFile.open(outfileName.c_str(), std::ios::out | std::ios::trunc);
	if (!outputFile.is_open())
		return (exitError("Output file can not be opened"));

	std::stringstream	buffer;
	std::string			findStr = argv[2];
	std::string			replStr = argv[3];
	std::size_t			oldPos = 0;
	std::size_t			newPos = 0;
	
	buffer << inputFile.rdbuf();
	while (newPos != std::string::npos)
	{
		newPos = buffer.str().find(findStr, newPos + 1);
		std::cout << "newPos: " << newPos << std::endl;
		if (newPos == std::string::npos)
		{
			std::cout << "No more str in buffer" << std::endl;
			outputFile << buffer.str().substr(oldPos, buffer.str().size());
			std::cout << "transfering from " << oldPos << " to " << buffer.str().size() << std::endl;
			sleep(10);
			continue ;
		}
		outputFile << buffer.str().substr(oldPos, newPos);
		std::cout << "transfering from " << oldPos << " to " << newPos << std::endl;
		outputFile << replStr;
		sleep(10);
		std::cout << "appending replStr" << std::endl;
		newPos += findStr.size();
		oldPos = newPos;
	}
		
	return (0);
}