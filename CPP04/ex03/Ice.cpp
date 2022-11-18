/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:03:26 by jchene            #+#    #+#             */
/*   Updated: 2022/11/18 18:38:01 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	if (MSGS > 0)
		std::cout << "Ice default c.tor called" << std::endl;
}

Ice::Ice(const Ice &ref) : AMateria("ice")
{
	if (MSGS > 0)
		std::cout << "Ice copy c.tor called" << std::endl;
	(void)ref;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (MSGS > 0)
		std::cout << "Ice copy assignment o.tor called" << std::endl;
	(void)rhs;
	return (*this);	
}

Ice::~Ice()
{
	if (MSGS > 0)
		std::cout << "Ice d.tor called" << std::endl;
}

Ice *Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter &target)
{ 
	(void)target;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}