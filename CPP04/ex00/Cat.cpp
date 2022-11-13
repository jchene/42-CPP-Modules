/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:29 by jchene            #+#    #+#             */
/*   Updated: 2022/11/13 17:22:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	if (MSGS > 0)
		std::cout << "Cat default c.tor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &ref) : Animal()
{
	if (MSGS > 0)
		std::cout << "Cat copy c.tor called" << std::endl;
	this->_type = ref.getType();
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (MSGS > 0)
		std::cout << "Cat copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

Cat::~Cat()
{
	if (MSGS > 0)
		std::cout << "Cat default d.tor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: *Meow Meow*" << std::endl;
}