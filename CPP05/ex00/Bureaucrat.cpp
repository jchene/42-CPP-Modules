/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:37:18 by jchene            #+#    #+#             */
/*   Updated: 2022/11/20 19:38:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//EXCEPTIONS
Bureaucrat::GradeTooHighException::GradeTooHighException(){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooHighException default c.tor called" << std::endl;}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &ref){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooHighException copy c.tor called" << std::endl;}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &rhs){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooHighException copy assignment o.tor called" << std::endl;}

Bureaucrat::GradeTooHighException::~GradeTooHighException(){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooHighException d.tor called" << std::endl;}

const char *Bureaucrat::GradeTooHighException::what() const { return ("Bureaucrat grade too high"); }

Bureaucrat::GradeTooLowException::GradeTooLowException(){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooLowException default c.tor called" << std::endl;}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &ref){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooLowException copy c.tor called" << std::endl;}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &rhs){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooLowException copy assignment o.tor called" << std::endl;}

Bureaucrat::GradeTooLowException::~GradeTooLowException(){
	if (MSGS > 2)
		std::cout << "Bureaucrat::GradeTooLowException d.tor called" << std::endl;}

const char *Bureaucrat::GradeTooLowException::what() const { return ("Bureaucrat grade too low"); }

//MEMBERS
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (MSGS > 0)
		std::cout << "Bureaucrat default c.tor called" << std::endl;
	if (grade < 1 || grade > 150)
		throw (this->GradeTooHighException::GradeTooHighException())
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

std::ostream &Bureaucrat::operator<<(std::ostream &lhs) const
{
	lhs << this->_name << ", bureaucrat grade " << this->_grade;
	return (lhs);
}

const std::string const &Bureaucrat::getName() const { return (this->_name); }

int const &Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::promote()
{
	if (this->_grade = 150)
		throw ();
	
}

void Bureaucrat::demote()
{}
