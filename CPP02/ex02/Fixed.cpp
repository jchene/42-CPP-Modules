/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:47 by jchene            #+#    #+#             */
/*   Updated: 2022/10/14 17:10:22 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &cpy) : _value(cpy._value) { std::cout << "Copy constructor called" << std::endl; }

Fixed::Fixed(const int nb) : _value(nb << this->_fBits) { std::cout << "Int constructor called" << std::endl; }

Fixed::Fixed(const float nb) : _value(roundf(nb * (1 << this->_fBits))) { std::cout << "Float constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&rhs != this)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed &Fixed::operator+(const Fixed &rhs) {  }

Fixed &Fixed::operator-(const Fixed &rhs) {}

Fixed &Fixed::operator*(const Fixed &rhs) {}

Fixed &Fixed::operator/(const Fixed &rhs) {}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
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