/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:37:18 by jchene            #+#    #+#             */
/*   Updated: 2022/11/19 19:56:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (MSGS > 0)
		std::cout << "Bureaucrat default c.tor called" << std::endl;
	if (grade < 1 || grade > 150)
		throw 
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref.getName())
{
	if (MSGS > 0)
		std::cout << "Bureaucrat default c.tor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{}

Bureaucrat::~Bureaucrat()
{}

const std::string const &Bureaucrat::getName() const
{}

int const &Bureaucrat::getGrade() const
{}

void Bureaucrat::promote()
{}

void Bureaucrat::demote()
{}
