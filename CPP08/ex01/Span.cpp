/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:53 by jchene            #+#    #+#             */
/*   Updated: 2022/12/30 00:48:42 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char *Span::arrayFullException::what() const throw()
{
	return ("Array is already full");
}

const char *Span::noSpanException::what() const throw()
{
	return ("No span could be found");
}

Span::Span(unsigned int N) : _maxSize(N)
{
	if (MSGS > 0)
		std::cout << "Default constructor called" << std::endl;
}

Span::Span(const Span &rhs)
{
	if (MSGS > 0)
		std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
	if (MSGS > 0)
		std::cout << "Assignment operator called" << std::endl;
	this->_maxSize = rhs.maxSize();
	std::copy(rhs.getArray().begin(), rhs.getArray().end(), this->_array.begin());
	return (*this);
}

Span::~Span()
{
	if (MSGS > 0)
		std::cout << "Default destructor called" << std::endl;
}

void Span::addNumber(int number)
{
	if (this->_array.size() == this->_maxSize)
		throw Span::arrayFullException();
	this->_array.insert(this->_array.begin(), number);
	sort(this->_array.begin(), this->_array.end());
}

unsigned int Span::shortestSpan() const
{
	if (this->_array.size() < 2)
		throw Span::noSpanException();
	unsigned int span = 4294967295U;
	intVec::const_iterator it1 = this->_array.begin();
	intVec::const_iterator it2 = this->_array.begin();
	it2++;
	for (; it2 != this->_array.end(); it2++)
	{
		if (static_cast<unsigned int>(*it2 - *it1) < span)
			span = static_cast<unsigned int>(*it2 - *it1);
		it1++;
	}
	return (span);
}

unsigned int Span::longestSpan() const
{
	if (this->_array.size() < 2)
		throw Span::noSpanException();
	int min = *min_element(this->_array.begin(), this->_array.end());
	int max = *max_element(this->_array.begin(), this->_array.end());
	return (static_cast<unsigned int>(max - min));
}

void Span::fillArray(intVec::const_iterator first, intVec::const_iterator last)
{
	for (intVec::const_iterator it = first; it != last; it++)
	{
		addNumber(*it);
	}
}

unsigned int Span::maxSize() const
{
	return (this->_maxSize);
}

const intVec &Span::getArray() const
{
	return (this->_array);
}

void Span::displaySpan()
{
	std::cout << "Span: ";
	std::copy(this->_array.begin(), this->_array.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}