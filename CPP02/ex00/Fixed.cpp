/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:47 by jchene            #+#    #+#             */
/*   Updated: 2022/10/19 17:35:19 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	if (MSGS > 0)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &cpy) : _value(cpy._value)
{
	if (MSGS > 0)
		std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &rhs)
{
	if (MSGS > 0)
		std::cout << "Copy assignment operator called" << std::endl;
	if (&rhs != this)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	if (MSGS > 0)
		std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	if (MSGS > 1)
		std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	if (MSGS > 1)
		std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}