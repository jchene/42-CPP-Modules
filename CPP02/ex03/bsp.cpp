/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:40:38 by jchene            #+#    #+#             */
/*   Updated: 2022/10/19 17:55:21 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed abs(Fixed nb) { return (nb < 0 ? nb * -1 : nb); }

Fixed getTriangleArea(Point const a, Point const b, Point const c)
{
	Fixed c1 = a.getX() * (b.getY() - c.getY());
	Fixed c2 = b.getX() * (c.getY() - a.getY());
	Fixed c3 = c.getX() * (a.getY() - b.getY());
	return (abs((c1 + c2 + c3) / 2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangleArea(getTriangleArea(a, b, c));
	Fixed areaSum(getTriangleArea(a, b, point));
	areaSum = areaSum + getTriangleArea(a, c, point);
	areaSum = areaSum + getTriangleArea(b, c, point);
	std::cout << "diff: " << abs(triangleArea - areaSum).toFloat() << std::endl;
	return (abs(triangleArea - areaSum) < Fixed(0.00001f));
}