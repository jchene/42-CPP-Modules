/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:44:22 by jchene            #+#    #+#             */
/*   Updated: 2022/12/29 18:07:58 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#define SIZE 50000

int main()
{
	Span test(SIZE);
	srand(time(NULL));
	try
	{
		test.addNumber(rand());
		std::cout << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		for (int i = 0; i < SIZE - 1; i++)
			test.addNumber(rand());
		std::cout << "longest span: " << test.longestSpan() << std::endl;
		std::cout << "shortest span: " << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test.addNumber(rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}