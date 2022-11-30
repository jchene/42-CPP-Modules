/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:46:58 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 14:53:41 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 10);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 100);
		std::cout << b2 << std::endl;
		// Bureaucrat b3("b3", -1);
		// Bureaucrat b4("b4", 151);
		Bureaucrat b5("b5", 1);
		std::cout << b5 << std::endl;
		// b5.promote();
		Bureaucrat b6("b5", 150);
		std::cout << b6 << std::endl;
		// b6.demote();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Catched:" << std::endl
				  << e.what() << std::endl;
		return (-1);
	}
	return (0);
}