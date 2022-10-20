/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:07:53 by jchene            #+#    #+#             */
/*   Updated: 2022/10/20 12:30:49 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
	if (MSGS > 0)
		std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const Point &ref) : _x(ref.getX()), _y(ref.getY())
{
	if (MSGS > 0)
		std::cout << "Point copy constructor called" << std::endl;
}

Point::Point(const int x, const int y) : _x(Fixed(x)), _y(Fixed(y))
{
	if (MSGS > 1)
		std::cout << "Point int constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	if (MSGS > 1)
		std::cout << "Point float constructor called" << std::endl;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
	if (MSGS > 1)
		std::cout << "Point Fixed constructor called" << std::endl;
}

Point::~Point()
{
	if (MSGS > 0)
		std::cout << "Point destructor called" << std::endl;
}

Point &Point::operator=(const Point &rhs)
{
	if (MSGS > 1)
		std::cout << "Point copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

bool Point::operator==(const Point &rhs) const
{
	if (MSGS > 1)
		std::cout << "Point comparison operator called" << std::endl;
	return ((this->getX() == rhs.getX()) && (this->getY() == rhs.getY()));
}

Fixed Point::getX() const { return (this->_x); }

Fixed Point::getY() const { return (this->_y); }
