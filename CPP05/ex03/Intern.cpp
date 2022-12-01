/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:18:29 by jchene            #+#    #+#             */
/*   Updated: 2022/12/01 17:08:15 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	if (MSGS > 0)
		std::cout << "Intern default c.tor called" << std::endl;
}

Intern::Intern(const Intern &ref)
{
	if (MSGS > 0)
		std::cout << "Intern copy c.tor called" << std::endl;
	(void)ref;
}

Intern &Intern::operator=(const Intern &rhs)
{
	if (MSGS > 0)
		std::cout << "Intern copy assignment o.tor called" << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	if (MSGS > 0)
		std::cout << "Intern d.tor called" << std::endl;
}

Form *Intern::makePPForm(std::string target)
{
	std::cout << "PPForm returned" << std::endl;
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeRRForm(std::string target)
{
	std::cout << "RRForm returned" << std::endl;
	return (new RobotomyRequestForm(target));
}

Form *Intern::makeSCForm(std::string target)
{
	std::cout << "SCForm returned" << std::endl;
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string formName, std::string target) const
{
	Intern temp;
	Form *(Intern::*ptrArray[3])(std::string) = { &Intern::makePPForm, &Intern::makeRRForm, &Intern::makeSCForm };
	std::string strArray[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
		if (formName.compare(strArray[i]) == 0)
			return ((temp.*ptrArray[i])(target));
	return (NULL);
}