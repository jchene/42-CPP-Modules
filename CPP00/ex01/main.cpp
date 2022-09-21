/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:48:42 by jchene            #+#    #+#             */
/*   Updated: 2022/09/21 17:48:45 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string str;
	PhoneBook	phoneBook;

	while (str != "EXIT")
	{
		std::cout << "\033c\0Please enter a command:" << std::endl;
		std::cin >> str;
		if (str == "ADD")
		{
			if (nbContacts == 0)
			{
				std::cout << "\033c\0----------[PhoneBook]----------" << std::endl;

			}
		}
		if (str == "SEARCH")
		{
			std::cout << "\033c\0----------[PhoneBook]----------" << std::endl;
			
		}
	}
	return (0);
}