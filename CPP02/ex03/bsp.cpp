/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:40:38 by jchene            #+#    #+#             */
/*   Updated: 2022/10/21 13:16:55 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#define POINT_EPSILON 0.0371094f

float floatAbs(float nb) { return (nb < 0 ? nb * -1 : nb); }

float getTriangleArea(Point const a, Point const b, Point const c)
{
	float c1 = (a.getX() * (b.getY() - c.getY())).toFloat();
	float c2 = (b.getX() * (c.getY() - a.getY())).toFloat();
	float c3 = (c.getX() * (a.getY() - b.getY())).toFloat();
	return (floatAbs((c1 + c2 + c3) / 2));
}

bool isBorder(Point const a, Point const b, Point const c, Point const point)
{
	if (!(getTriangleArea(a, b, point) > POINT_EPSILON
			&& getTriangleArea(a, c, point) > POINT_EPSILON
			&& getTriangleArea(b, c, point) > POINT_EPSILON))
	{
		std::cout << "Point is in border of triangle" << std::endl;
		return (true);
	}
	return (false);
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
	if (triangleArea != areaSum)
	{
		std::cout << "Point not in triangle" << std::endl;
		return (false);
	}
	return (!(isBorder(a, b, c, point)));
}
