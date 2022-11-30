/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:22:43 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 17:36:34 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// EXCEPTIONS
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

// COPLIEN
Form::Form(std::string name, int sGrade, int eGrade) : _name(name), _signed(0), _signGrade(checkGrade(sGrade, ALL_BD)), _execGrade(checkGrade(eGrade, ALL_BD))
{
	if (MSGS > 0)
		std::cout << "Form default c.tor called" << std::endl;
}

Form::Form(const Form &ref) : _name(ref.getName()), _signed(0), _signGrade(ref.getSignGrade()), _execGrade(ref.getExecGrade())
{
	if (MSGS > 0)
		std::cout << "Form copy c.tor called" << std::endl;
	(void)ref;
}

Form &Form::operator=(const Form &rhs)
{
	if (MSGS > 0)
		std::cout << "Form copy assignment o.tor called" << std::endl;
	(void)rhs;
	return (*this);
}

Form::~Form()
{
	if (MSGS > 0)
		std::cout << "Form d.tor called" << std::endl;
}

// MEMBERS
const std::string &Form::getName() const { return (this->_name); }

bool Form::getSign() const { return (this->_signed); }

const int &Form::getSignGrade() const { return (this->_signGrade); }

const int &Form::getExecGrade() const { return (this->_execGrade); }

int Form::checkGrade(int grade, int bound)
{
	switch (bound)
	{
	case (UPR_BD):
		if (grade < 1)
			throw(Form::GradeTooHighException());
		break;
	case (LWR_BD):
		if (grade > 150)
			throw(Form::GradeTooLowException());
		break;
	case (ALL_BD):
		if (grade < 1)
			throw(Form::GradeTooHighException());
		if (grade > 150)
			throw(Form::GradeTooLowException());
		break;
	default:
		break;
	}
	return (grade);
}

void Form::beSigned(const Bureaucrat &ref)
{
	if (ref.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw(Form::GradeTooLowException());
}

// NON-MEMBERS
std::ostream &operator<<(std::ostream &lhs, const Form &rhs)
{
	lhs << "*" << rhs.getName() << ", signed: " << rhs.getSign() << ", sign grade: " << rhs.getSignGrade() << ", exec grade: " << rhs.getExecGrade() << "*";
	return (lhs);
}