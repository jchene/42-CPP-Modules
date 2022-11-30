/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:02:59 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 19:45:49 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
	std::string _target;

	public:
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm();

	const std::string &getTarget() const;
	void execute(Bureaucrat const &executor) const;
};

#endif