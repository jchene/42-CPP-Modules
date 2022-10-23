/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/10/24 00:58:17 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Unnamed Diamond")
{
	this->ClapTrap::_name = _name + "_clap_name";
	if (MSGS > 0)
		std::cout << this->_name << " DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	this->ClapTrap::_name = _name + "_clap_name";
	if (MSGS > 0)
		std::cout << this->_name << " DiamondTrap string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref), _name(this->ClapTrap::_name)
{
	this->ClapTrap::_name = _name + "_clap_name";
	if (MSGS > 0)
		std::cout << this->_name << " DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	if (MSGS > 0)
		std::cout << this->_name << " DiamondTrap copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() 
{
	if (MSGS > 0)
		std::cout << this->_name << " DiamondTrap destructor called, no more diamonds!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << this->_name << ": My name is \"" << this->_name << "\", son of \"" << this->ClapTrap::_name << "\"." << std::endl
				<< "I have " << this->_hitPoints << " hit points, " << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage." << std::endl
				<< "Am I on guard mode: " << this->_guardMode << std::endl;
}
