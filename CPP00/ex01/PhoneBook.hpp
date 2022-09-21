/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:47:08 by jchene            #+#    #+#             */
/*   Updated: 2022/09/21 18:10:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
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
	void displayAll();
};

std::string trunc(std::string str){
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str.substr(0, 10));
}



