/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:44:22 by jchene            #+#    #+#             */
/*   Updated: 2022/12/30 00:49:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#define SIZE 5

int main()
{
	Span test(SIZE);
	srand(time(NULL));
	try
	{
		test.addNumber(rand() % 10);
		std::cout << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		for (int i = 0; i < SIZE - 1; i++)
			test.addNumber(rand() % 10);
		std::cout << "longest span: " << test.longestSpan() << std::endl;
		std::cout << "shortest span: " << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		test.addNumber(rand() % 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	Span fillTest(5);
	try
	{
		
		test.displaySpan();
		fillTest.fillArray(test.getArray().begin(), test.getArray().end());
		fillTest.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	Span fillTest2(11);
	try
	{
		fillTest2.fillArray(test.getArray().begin(), test.getArray().end());
		fillTest2.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}