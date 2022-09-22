/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:46:56 by jchene            #+#    #+#             */
/*   Updated: 2022/09/22 13:39:06 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():_nbContacts(0)
{
	std::cout << "TEST" << std::endl;\
}

void PhoneBook::newContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->_array[this->_nbContacts].setFirstName(firstName);
	this->_array[this->_nbContacts].setLastName(lastName);
	this->_array[this->_nbContacts].setNickname(nickname);
	this->_array[this->_nbContacts].setPhoneNumber(phoneNumber);
	this->_array[this->_nbContacts].setDarkestSecret(darkestSecret);
	this->_nbContacts++;
	this->_nbContacts %= 8;
}

void PhoneBook::displayContact(int id)
{
	std::string tmpStr;
	std::cout << "|" << this->_array[id].getId();
	for (unsigned long i = 0; i < 9; i++)
		std::cout << " ";

	tmpStr = this->_array[id].getFirstName();
	std::cout << "|" << trunc(tmpStr);
	for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
		std::cout << " ";

	tmpStr = this->_array[id].getLastName();
	std::cout << "|" << trunc(tmpStr);
	for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
		std::cout << " ";

	tmpStr = this->_array[id].getNickname();
	std::cout << "|" << trunc(tmpStr);
	for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
		std::cout << " ";

	tmpStr = this->_array[id].getDarkestSecret();
	std::cout << "|" << trunc(tmpStr);
	for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
		std::cout << " ";
	std::cout << "|" << std::endl;
}

void PhoneBook::displayPreview()
{
	std::string tmpStr;
	for (int i = 0; i < this->_nbContacts; i++)
	{
		std::cout << "|" << this->_array[i].getId();
		for (unsigned long i = 0; i < 9; i++)
			std::cout << " ";

		tmpStr = this->_array[i].getFirstName();
		std::cout << "|" << trunc(tmpStr);
		for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
			std::cout << " ";

		tmpStr = this->_array[i].getLastName();
		std::cout << "|" << trunc(tmpStr);
		for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
			std::cout << " ";

		tmpStr = this->_array[i].getNickname();
		std::cout << "|" << trunc(tmpStr);
		for (unsigned long i = 0; i < 10 - tmpStr.length(); i++)
			std::cout << " ";
		std::cout << "|" << std::endl;
	}
}

int PhoneBook::getNbContacts()
{
	return (this->_nbContacts);
}

std::string trunc(std::string str){
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str.substr(0, 10));
}