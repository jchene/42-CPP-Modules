/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:47 by jchene            #+#    #+#             */
/*   Updated: 2022/10/21 14:54:26 by jchene           ###   ########.fr       */
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

Fixed Fixed::operator+(const Fixed &rhs) const { return (Fixed(this->toFloat() + rhs.toFloat())); }

Fixed Fixed::operator-(const Fixed &rhs) const { return (Fixed(this->toFloat() - rhs.toFloat())); }

Fixed Fixed::operator*(const Fixed &rhs) const { return (Fixed(this->toFloat() * rhs.toFloat())); }

Fixed Fixed::operator/(const Fixed &rhs) const { return (Fixed(this->toFloat() / rhs.toFloat())); }

bool Fixed::operator>(const Fixed &rhs) const { return (this->toFloat() > rhs.toFloat()); }

bool Fixed::operator<(const Fixed &rhs) const { return (this->toFloat() < rhs.toFloat()); }

bool Fixed::operator>=(const Fixed &rhs) const { return (this->toFloat() >= rhs.toFloat()); }

bool Fixed::operator<=(const Fixed &rhs) const { return (this->toFloat() <= rhs.toFloat()); }

bool Fixed::operator==(const Fixed &rhs) const { return (this->toFloat() == rhs.toFloat()); }

bool Fixed::operator!=(const Fixed &rhs) const { return (this->toFloat() != rhs.toFloat()); }

Fixed Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result(this->toFloat());
	this->setRawBits(this->getRawBits() + 1);
	return (result);
}

Fixed Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed result(this->toFloat());
	this->setRawBits(this->getRawBits() - 1);
	return (result);
}

int Fixed::getRawBits(void) const { return (this->_value); }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

int Fixed::toInt(void) const { return (this->_value / (1 << this->_fBits)); }

float Fixed::toFloat(void) const { return (this->_value / roundf(1 << this->_fBits)); }

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2) { return ((ref1 < ref2) ? ref1 : ref2); }

const Fixed &Fixed::min(const Fixed &ref1, const Fixed &ref2) { return ((ref1 < ref2) ? ref1 : ref2); }

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2) { return ((ref1 > ref2) ? ref1 : ref2); }

const Fixed &Fixed::max(const Fixed &ref1, const Fixed &ref2) { return ((ref1 > ref2) ? ref1 : ref2); }

std::ostream &operator<<(std::ostream &stream, const Fixed &ref)
{
	stream << ref.toFloat();
	return (stream);
}