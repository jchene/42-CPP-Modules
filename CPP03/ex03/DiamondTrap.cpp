/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:40:28 by jchene            #+#    #+#             */
/*   Updated: 2022/11/12 19:08:18 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	if (MSGS > 0)
		std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "unnamed Diamond";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap().getHp();
	this->_energyPoints = ScavTrap().getEp();
	this->_attackDamage = FragTrap().getAd();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), ScavTrap(), FragTrap()
{
	if (MSGS > 0)
		std::cout << "DiamondTrap string constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap().getHp();
	this->_energyPoints = ScavTrap().getEp();
	this->_attackDamage = FragTrap().getAd();
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(), ScavTrap(), FragTrap()
{
	if (MSGS > 0)
		std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = ref._name;
	this->ClapTrap::_name = ref.ClapTrap::getName();
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->ClapTrap::_name = rhs.ClapTrap::getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	if (MSGS > 0)
		std::cout << "DiamondTrap destructor called" << std::endl;
}

std::string DiamondTrap::getName() const { return (this->_name); }

unsigned int DiamondTrap::getHp() const { return (this->_hitPoints); }

unsigned int DiamondTrap::getEp() const { return (this->_energyPoints); }

unsigned int DiamondTrap::getAd() const { return (this->_attackDamage); }

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); };

void DiamondTrap::whoAmI()
{
	std::cout << "Hello, my name is " << this->_name << " and my clap_name is " << ClapTrap::getName() << std::endl;
}
