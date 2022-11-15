/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:29 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:39:17 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	if (MSGS > 0)
		std::cout << "Cat default c.tor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &ref) : Animal()
{
	if (MSGS > 0)
		std::cout << "Cat copy c.tor called" << std::endl;
	this->_type = ref.getType();
	this->_brain = new Brain();
	*(this->_brain) = *(ref.getBrain());
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (MSGS > 0)
		std::cout << "Cat copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	return (*this);
}

Cat::~Cat()
{
	if (MSGS > 0)
		std::cout << "Cat default d.tor called" << std::endl;
	delete(this->_brain);
}

void Cat::makeSound() const
{
	std::cout << "Cat: *Meow Meow*" << std::endl;
}

Brain *Cat::getBrain() const { return (this->_brain); }