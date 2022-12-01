/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:02:57 by jchene            #+#    #+#             */
/*   Updated: 2022/12/01 15:58:46 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
	std::string _target;

	public:
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();

	const std::string &getTarget() const;
	void execute(Bureaucrat const &executor) const;
};

#endif