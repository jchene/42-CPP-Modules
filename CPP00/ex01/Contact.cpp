/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:37:06 by jchene            #+#    #+#             */
/*   Updated: 2022/09/21 17:47:59 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	this->_id = -1;
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

std::string Contact::getFirstName(){
	return(this->_firstName);
}

std::string Contact::getLastName(){
	return(this->_lastName);
}

std::string Contact::getNickname(){
	return(this->_nickname);
}

std::string Contact::getPhoneNumber(){
	return(this->_phoneNumber);
}

std::string Contact::getDarkestSecret(){
	return(this->_darkestSecret);
}

int Contact::getId(){
	return(this->_id);
}

void Contact::setFirstName(std::string firstName){
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName){
	this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname){
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber){
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret){
	this->_darkestSecret = darkestSecret;
}

void Contact::setId(int id){
	this->_id = id;
}
