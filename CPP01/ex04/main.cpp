/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:58 by jchene            #+#    #+#             */
/*   Updated: 2022/10/06 16:21:45 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int exitError(const char *str)
{
	std::cout << str << std::endl;
	return (-1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (exitError("Bad number of arguments"));

	std::fstream		file;
	std::string			infileName = argv[1];
	std::stringstream	buffer;

	file.open(infileName.c_str(), std::ios::in);
	if (!file.is_open())
		return (exitError("Input file can not be opened"));
	buffer << file.rdbuf();
	file.close();
	file.open(infileName.append(".replace").c_str() , std::ios::out | std::ios::trunc);
	if (!file.is_open())
		return (exitError("Output file can not be opened"));

	std::string		findStr = argv[2];
	std::string		replStr = argv[3];
	std::size_t		oldPos = 0;
	std::size_t		newPos = 0;
	
	while (newPos != std::string::npos)
	{
		newPos = buffer.str().find(findStr, newPos + 1);
		if (newPos == std::string::npos)
		{
			file << buffer.str().substr(oldPos, buffer.str().size() - oldPos);
			continue ;
		}
		file << buffer.str().substr(oldPos, newPos - oldPos) << replStr;
		newPos += findStr.size();
		oldPos = newPos;
	}
	file.close();
	return (0);
}