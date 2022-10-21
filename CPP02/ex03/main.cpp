/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:12 by jchene            #+#    #+#             */
/*   Updated: 2022/10/21 13:16:36 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(-25.3f, 21.6f);
	Point b(12, 13);
	Point c(4, -3);
	Point point(-18.2f, 4.5f);
	Point point2(-5, 12);
	Point point3(4, -3);
	Point point4(-4.9f, 16.9f);
	Point point5(-4.9145f, 16.8998f);
	Point point6(-4.914508919431277f, 16.89985996533804f);
	Point point7(-4.914478482834081f,16.899875598948917f);
	Point point8(-4.91452f,16.89974f);
	bool inTriangle = bsp(a, b, c, point5);
	if (inTriangle)
		std::cout << "Point is in triangle" << std::endl;
	return (0);
}