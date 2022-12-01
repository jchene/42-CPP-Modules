/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:37:18 by jchene            #+#    #+#             */
/*   Updated: 2022/12/01 18:52:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//EXCEPTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Bureaucrat grade too high"); }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Bureaucrat grade too low"); }

//MEMBERS
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (MSGS > 0)
		std::cout << "Bureaucrat default c.tor called" << std::endl;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref.getName())
{
	if (MSGS > 0)
		std::cout << "Bureaucrat copy c.tor called" << std::endl;
	this->_grade = ref.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (MSGS > 0)
		std::cout << "Bureaucrat copy assignment o.tor called" << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (MSGS > 0)
		std::cout << "Bureaucrat d.tor called" << std::endl;
}

const std::string &Bureaucrat::getName() const { return (this->_name); }

int const &Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::promote()
{
	if (this->_grade == 1)
		throw (GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::demote()
{
	if (this->_grade == 150)
		throw (GradeTooLowException());
	this->_grade++;
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &ref)
{
	lhs << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (lhs);
}