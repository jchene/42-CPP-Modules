/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:48:42 by jchene            #+#    #+#             */
/*   Updated: 2022/09/22 16:58:19 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string str;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	int i;

	std::cout << "\033c";
	while (str != "EXIT")
	{
		std::cout << "Please enter a command:" << std::endl;
		std::cin >> str;
		if (str == "ADD")
		{
			firstName = "";
			lastName = "";
			nickname = "";
			phoneNumber = "";
			darkestSecret = "";
			while (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
			{
				std::cout << "\033c" << "Creating contact" << std::endl << std::endl;
				std::cout << " First Name: ";
				if (firstName.empty())
				{
					std::getline(std::cin, firstName);
					if (firstName.empty())
						continue;
				}
				else
					std::cout << firstName << std::endl;

				std::cout << " Last Name: ";
				if (lastName.empty())
				{
					std::getline(std::cin, lastName);
					if (lastName.empty())
						continue;
				}
				else
					std::cout << lastName << std::endl;

				std::cout << " Nickname: ";
				if (nickname.empty())
				{
					std::getline(std::cin, nickname);
					if (nickname.empty())
						continue;
				}
				else
					std::cout << nickname << std::endl;

				std::cout << " Phone Number: ";
				if (phoneNumber.empty())
				{
					std::getline(std::cin, phoneNumber);
					if (phoneNumber.empty())
						continue;
				}
				else
					std::cout << phoneNumber << std::endl;

				std::cout << " Darkest Secret: ";
				if (darkestSecret.empty())
				{
					std::getline(std::cin, darkestSecret);
					if (darkestSecret.empty())
						continue;
				}
				else
					std::cout << darkestSecret << std::endl;
			}
			phoneBook.newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			std::cout << "\033c" << "Contact created" << std::endl << std::endl;
		}
		else if (str == "SEARCH")
		{
			std::cout << "\033c";
			phoneBook.displayPreview();
			std::cout << "Select contact id:" << std::endl;
			std::cin >> str;
			std::istringstream(str) >> i;
			if (str.find_first_not_of("0123456789") == std::string::npos && i >= 0 && i < phoneBook.getNbContacts())
				phoneBook.displayContact(i);
			else
				std::cout << "\033c"
						  << "Please enter a valid contact id" << std::endl
						  << std::endl;
		}
		else
			std::cout << "\033c"
					  << "Valid commands are: ADD, SEARCH, EXIT" << std::endl
					  << std::endl;
	}
	return (0);
}