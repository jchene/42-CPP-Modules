/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:47:08 by jchene            #+#    #+#             */
/*   Updated: 2022/09/22 16:05:51 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
private:
	int		_nbContacts;
	Contact _array[8];

public:
	PhoneBook();
	void newContact(std::string, std::string, std::string, std::string, std::string);
	void displayContact(int id);
	void displayPreview();
	int getNbContacts();
};

std::string trunc(std::string str);



