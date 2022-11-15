/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:10:29 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 15:23:49 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	if (MSGS > 0)
		std::cout << "WrongAnimal default c.tor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	if (MSGS > 0)
		std::cout << "WrongAnimal copy c.tor called" << std::endl;
	this->_type = ref.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (MSGS > 0)
		std::cout << "WrongAnimal copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	if (MSGS > 0)
		std::cout << "WrongAnimal default d.tor called" << std::endl;
}

std::string WrongAnimal::getType() const { return(this->_type); }

void WrongAnimal::makeSound() const
{
	std::cout << this->_type << ": *WrongAnimal growl*" << std::endl;
}