/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:41:48 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 20:15:56 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// COPLIEN
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("rrForm", 72, 45), _target(target)
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm default c.tor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : Form("rrForm", 72, 45), _target(ref.getTarget())
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm copy c.tor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm copy assignment o.tor called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm d.tor called" << std::endl;
}

// MEMBERS
const std::string &RobotomyRequestForm::getTarget() const { return (this->_target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw(Form::UnsignedFormException());
	else if (executor.getGrade() > this->_execGrade)
		throw(Form::GradeTooLowException());
	else
	{
		if (std::rand() % 2)
			std::cout << this->_target << " has been robotomized." << std::endl;
		else
			std::cout << "The robotomy failed." << std::endl;
	}
}