/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:48:42 by jchene            #+#    #+#             */
/*   Updated: 2022/09/22 13:34:22 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string str;
	char *id = NULL;
	PhoneBook phoneBook;

	while (str != "EXIT")
	{
		std::cout << "Please enter a command:" << std::endl;
		std::cin >> str;
		if (str == "ADD")
		{
			if (phoneBook.getNbContacts() == 0)
			{
				std::cout << "\033c";
				std::cout << "------------------[PhoneBook]-----------------" << std::endl;
				phoneBook.newContact("fn1", "ln", "nn", "pn", "ds");
				phoneBook.newContact("fn2", "ln", "nn", "pn", "ds");
				std::cout << "Added contacts" << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
			}
		}
		if (str == "SEARCH")
		{
			std::cout << "\033c";
			std::cout << "------------------[PhoneBook]-----------------" << std::endl;
			if (phoneBook.getNbContacts() > 0)
				phoneBook.displayPreview();
			std::cout << "----------------------------------------------" << std::endl;
			if (phoneBook.getNbContacts() > 0)
			{
				while (std::atoi(id) < 0 || std::atoi(id) > phoneBook.getNbContacts())
				{
					std::cout << "Select contact id:" << std::endl;
					std::cin >> id;
				}
				phoneBook.displayContact(std::atoi(id));
			}
		}
	}
	return (0);
}