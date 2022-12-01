/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:46:58 by jchene            #+#    #+#             */
/*   Updated: 2022/12/01 16:59:56 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 6);
		std::cout << b1 << std::endl;
		Intern slave;
		Form *f1 = slave.makeForm("robotomy request", "david");
		std::cout << *f1 << std::endl;
		Form *f2 = slave.makeForm("presidential pardon", "tom");
		std::cout << *f2 << std::endl;
		Form *f3 = slave.makeForm("shrubbery creation", "george");
		std::cout << *f3 << std::endl;
		Form *f4 = slave.makeForm("wtf is that", "fred");
		std::cout << f4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Catched:" << std::endl
				  << e.what() << std::endl;
		return (-1);
	}
	return (0);
}