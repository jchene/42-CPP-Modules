/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:42:07 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 20:27:15 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// COPLIEN
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("scForm", 145, 137), _target(target)
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm default c.tor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : Form("scForm", 145, 137), _target(ref.getTarget())
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm copy c.tor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm copy assignment o.tor called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (MSGS > 0)
		std::cout << "PresidentianPardonForm d.tor called" << std::endl;
}

// MEMBERS
const std::string &ShrubberyCreationForm::getTarget() const { return (this->_target); }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw(Form::UnsignedFormException());
	else if (executor.getGrade() > this->_execGrade)
		throw(Form::GradeTooLowException());
	else
	{
		std::ofstream outfile;
		std::string newName = this->_target + "_shrubbery";
		outfile.open(newName.c_str(), std::ios::trunc);
		if (!outfile.is_open())
		{
			std::cout << "Outfile couldn't be opened" << std::endl;
			return;
		}
		outfile << "    oxoxoo    ooxoo		     ccee88oo" << std::endl;
		outfile << "  ooxoxo oo  oxoxooo	  C8O8O8Q8PoOb o8oo" << std::endl;
		outfile << " oooo xxoxoo ooo ooox	 dOB69QO8PdUOpugoO9bD" << std::endl;
		outfile << " oxo o oxoxo  xoxxoxo	CgggbU8OU qOp qOdoUOdcb" << std::endl;
		outfile << "  oxo xooxoooo o ooo	    6OuU  /p u gcoUodpP" << std::endl;
		outfile << "    ooo\\oo\\  /o/o	      \\\\//  /douUP" << std::endl;
		outfile << "        \\  \\/ /		        \\\\////" << std::endl;
		outfile << "         |   /		         |||/\\" << std::endl;
		outfile << "         |  |		         |||\\/" << std::endl;
		outfile << "         | D|		         |||||" << std::endl;
		outfile << "         |  |		         |||||" << std::endl;
		outfile << "         |  |		         |||||" << std::endl;
		outfile << "________/____\\_________________//||||\\____" << std::endl;
		outfile.close();
	}
}