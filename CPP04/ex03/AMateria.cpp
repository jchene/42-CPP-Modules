/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:54:35 by jchene            #+#    #+#             */
/*   Updated: 2022/11/18 19:21:10 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	if (MSGS > 0)
		std::cout << "AMateria default c.tor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &ref)
{
	if (MSGS > 0)
		std::cout << "AMateria copy c.tor called" << std::endl;
	this->_type = ref.getType();
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (MSGS > 0)
		std::cout << "AMateria copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
}

AMateria::~AMateria()
{
	if (MSGS > 0)
		std::cout << "AMateria d.tor called" << std::endl;
}

std::string const &AMateria::getType() const { return (this->_type); }

void AMateria::use(ICharacter &target)
{ 
	(void)target;
	std::cout << "*It does nothing*" << std::endl;
}