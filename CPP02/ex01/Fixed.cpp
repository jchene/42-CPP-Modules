/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:47 by jchene            #+#    #+#             */
/*   Updated: 2022/10/19 17:32:27 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	if (MSGS > 0)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy) : _value(cpy._value)
{
	if (MSGS > 0)
		std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : _value(nb << this->_fBits)
{
	if (MSGS > 1)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb) : _value(roundf(nb * (1 << this->_fBits)))
{
	if (MSGS > 1)
		std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
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

int Fixed::toInt(void) const { return (this->_value / (1 << this->_fBits)); }

float Fixed::toFloat(void) const { return (this->_value / roundf(1 << this->_fBits)); }

std::ostream &operator<<(std::ostream &stream, const Fixed &ref)
{
	stream << ref.toFloat();
	return (stream);
}