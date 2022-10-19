/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:13:12 by jchene            #+#    #+#             */
/*   Updated: 2022/10/19 17:54:42 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*int main(void)
{
	Point a(-25.3f, 21.6f);
	Point b(12, 13);
	Point c(4, -3);
	Point point(-18.2f, 4.5f);
	Point point2(-5, 12);
	bool inTriangle = bsp(a, b, c, point2);

	std::cout << "Point is in triangle: " << inTriangle << std::endl;
	return (0);
}*/

int main(void)
{
	Point a(-25.3f, 21.6f);
	Point b(12, 13);
	Point c(4, -3);
	Point point(-18.2f, 4.5f);
	Point point2(-5, 12);
	Point point3(4, -3);
	bool inTriangle = bsp(a, b, c, point3);

	std::cout << "Point is in triangle: " << inTriangle << std::endl;
	return (0);
}