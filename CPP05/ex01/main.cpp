/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:46:58 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 17:38:05 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 2);
		std::cout << b1 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		b1.promote();
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		//Form f2("f2", 0, 1);
		//Form f3("f3", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Catched:" << std::endl
				  << e.what() << std::endl;
		return (-1);
	}
	return (0);
}