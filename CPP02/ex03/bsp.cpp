/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:40:38 by jchene            #+#    #+#             */
/*   Updated: 2022/10/20 12:57:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float fAbs(float nb) { return (nb < 0 ? nb * -1 : nb); }

Fixed FiAbs(Fixed nb) { return (nb < 0 ? nb * -1 : nb); }

float getTriangleArea(Point const a, Point const b, Point const c)
{
	float c1 = (a.getX() * (b.getY() - c.getY())).toFloat();
	float c2 = (b.getX() * (c.getY() - a.getY())).toFloat();
	float c3 = (c.getX() * (a.getY() - b.getY())).toFloat();
	return (fAbs((c1 + c2 + c3) / 2));
}

bool isBorder(Point const a, Point const b, Point const point)
{
	Fixed crossProduct;
	crossProduct = (point.getY()-a.getY()) * (b.getX()-a.getX()) - (point.getX()-a.getX()) * (b.getY()-a.getY());
	if (FiAbs(crossProduct) <= 0)
		std::cout << "Is on border" << std::endl;
	return (FiAbs(crossProduct) <= 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float triangleArea = getTriangleArea(a, b, c);
	float areaSum(getTriangleArea(a, b, point));
	if (point == a || point == b || point == c)
	{
		std::cout << "Point is triangle point" << std::endl;
		return (false);
	}
	areaSum = areaSum + getTriangleArea(a, c, point);
	areaSum = areaSum + getTriangleArea(b, c, point);
	std::cout << "diff: " << fAbs(triangleArea - areaSum) << std::endl;
	if (triangleArea != areaSum)
	{
		std::cout << "Point not in triangle" << std::endl;
		return (false);
	}
	return (!(isBorder(a, b, point) || isBorder(a, c, point) || isBorder(b, c, point)));
}
