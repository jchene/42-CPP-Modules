/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Acat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:30 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:52:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACat.hpp"

ACat::ACat() : Animal()
{
	if (MSGS > 0)
		std::cout << "ACat default c.tor called" << std::endl;
	this->_type = "ACat";
	this->_brain = new Brain();
}

ACat::ACat(const ACat &ref) : Animal()
{
	if (MSGS > 0)
		std::cout << "ACat copy c.tor called" << std::endl;
	this->_type = ref.getType();
	this->_brain = new Brain();
	*(this->_brain) = *(ref.getBrain());
}

ACat &ACat::operator=(const ACat &rhs)
{
	if (MSGS > 0)
		std::cout << "ACat copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	*(this->_brain) = *(rhs.getBrain());
	return (*this);
}

ACat::~ACat()
{
	if (MSGS > 0)
		std::cout << "ACat default d.tor called" << std::endl;
	delete(this->_brain);
}

Brain *ACat::getBrain() const { return (this->_brain); }