/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:02:55 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 19:46:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
	std::string _target;

	public:
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm();

	const std::string &getTarget() const;
	void execute(Bureaucrat const &executor) const;
};

#endif