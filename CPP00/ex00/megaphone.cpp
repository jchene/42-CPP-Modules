/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:15:17 by jchene            #+#    #+#             */
/*   Updated: 2022/09/21 14:53:18 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./megaphone.hpp"

int main(int argc, char **argv)
{
	std::locale loc;
	std::string str;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.size(); j++)
			std::cout << std::toupper(str[j], loc);
	}
	std::cout << std::endl;
	return (0);
}