/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:40:28 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 21:20:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("unnamed Diamond")
{
	if (MSGS > 0)
		std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	if (MSGS > 0)
		std::cout << "DiamondTrap string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : FragTrap(), ScavTrap(), _name(ref._name)
{
	if (MSGS > 0)
		std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	this->_name = rhs.ClapTrap::getName()
}

DiamondTrap::~DiamondTrap()
{
	if (MSGS > 0)
		std::cout << "DiamondTrap destructor called" << std::endl;
}

void attack(const std::string &target)
{
}

void whoAmI()
{
}
