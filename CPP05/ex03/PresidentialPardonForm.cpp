/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:07:36 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 20:15:53 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// COPLIEN
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("ppForm", 25, 5), _target(target)
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm default c.tor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : Form("ppForm", 25, 5), _target(ref.getTarget())
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm copy c.tor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm copy assignment o.tor called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm d.tor called" << std::endl;
}

// MEMBERS
const std::string &PresidentialPardonForm::getTarget() const { return (this->_target); }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw(Form::UnsignedFormException());
	else if (executor.getGrade() > this->_execGrade)
		throw(Form::GradeTooLowException());
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}