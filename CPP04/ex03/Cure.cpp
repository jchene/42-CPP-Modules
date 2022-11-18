/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:03:06 by jchene            #+#    #+#             */
/*   Updated: 2022/11/18 18:38:08 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	if (MSGS > 0)
		std::cout << "Cure default c.tor called" << std::endl;
}

Cure::Cure(const Cure &ref) : AMateria("cure")
{
	if (MSGS > 0)
		std::cout << "Cure copy c.tor called" << std::endl;
	(void)ref;
}

Cure &Cure::operator=(const Cure &rhs)
{
	if (MSGS > 0)
		std::cout << "Cure copy assignment o.tor called" << std::endl;
	(void)rhs;
	return (*this);	
}

Cure::~Cure()
{
	if (MSGS > 0)
		std::cout << "Cure d.tor called" << std::endl;
}

Cure *Cure::clone() const { return (new Cure()); }

void Cure::use(ICharacter &target)
{ 
	(void)target;
	std::cout << "* heals " << target.getName() << " *’s wounds *" << std::endl;
}