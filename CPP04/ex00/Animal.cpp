/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:30:03 by jchene            #+#    #+#             */
/*   Updated: 2022/11/13 17:22:58 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	if (MSGS > 0)
		std::cout << "Animal default c.tor called" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	if (MSGS > 0)
		std::cout << "Animal copy c.tor called" << std::endl;
	this->_type = ref.getType();
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (MSGS > 0)
		std::cout << "Animal copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

Animal::~Animal()
{
	if (MSGS > 0)
		std::cout << "Animal default d.tor called" << std::endl;
}

std::string Animal::getType() const { return(this->_type); }

void Animal::makeSound() const
{
	std::cout << "Animal: *unrecognizable growl from hell*" << std::endl;
}