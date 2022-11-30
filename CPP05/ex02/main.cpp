/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:46:58 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 20:19:22 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 6);
		Bureaucrat b2("b2", 26);
		std::cout << b1 << std::endl;

		PresidentialPardonForm pp("Mr.Smith");
		b1.executeForm(pp);
		b2.signForm(pp);
		b1.signForm(pp);
		b1.executeForm(pp);
		b1.promote();
		b1.executeForm(pp);
		RobotomyRequestForm rr("Mr.Jack");
		b1.signForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		b1.executeForm(rr);
		ShrubberyCreationForm sc("home");
		b1.signForm(sc);
		b1.executeForm(sc);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Catched:" << std::endl
				  << e.what() << std::endl;
		return (-1);
	}
	return (0);
}