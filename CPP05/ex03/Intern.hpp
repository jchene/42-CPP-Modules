/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:06:51 by jchene            #+#    #+#             */
/*   Updated: 2022/12/01 16:13:24 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <sstream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &ref);
	Intern &operator=(const Intern &rhs);
	~Intern();

	Form *makeSCForm(std::string target);
	Form *makeRRForm(std::string target);
	Form *makePPForm(std::string target);
	Form *makeForm(std::string formName, std::string target) const;
};

#endif