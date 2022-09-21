/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:46:56 by jchene            #+#    #+#             */
/*   Updated: 2022/09/21 18:16:52 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->_nbContacts = 0;
}

void PhoneBook::newContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret){
	this->_array[this->_nbContacts].setFirstName(firstName);
	this->_array[this->_nbContacts].setLastName(lastName);
	this->_array[this->_nbContacts].setNickname(nickname);
	this->_array[this->_nbContacts].setPhoneNumber(phoneNumber);
	this->_array[this->_nbContacts].setDarkestSecret(darkestSecret);
	this->_nbContacts++;
	_nbContacts = _nbContacts % 8;
}

void PhoneBook::displayContact(int id){
	std::cout << "|" << this->_array[id].getId();
	std::cout << "|" << trunc(this->_array[id].getFirstName());
	std::cout << "|" << trunc(this->_array[id].getLastName());
	std::cout << "|" << trunc(this->_array[id].getNickname());
	std::cout << "|" << std::endl;
}