/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:38:03 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:39:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	if (MSGS > 0)
		std::cout << "Dog default c.tor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &ref) : Animal()
{
	if (MSGS > 0)
		std::cout << "Dog copy c.tor called" << std::endl;
	this->_type = ref.getType();
	this->_brain = new Brain();
	*(this->_brain) = *(ref.getBrain());
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (MSGS > 0)
		std::cout << "Dog copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	return (*this);
}

Dog::~Dog()
{
	if (MSGS > 0)
		std::cout << "Dog default d.tor called" << std::endl;
	delete(this->_brain);
}

void Dog::makeSound() const
{
	std::cout << "Dog: *Woof Woof*" << std::endl;
}

Brain *Dog::getBrain() const { return (this->_brain); }