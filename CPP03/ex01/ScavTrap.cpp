/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 18:17:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _guardMode(false)
{
	if (MSGS > 0)
		std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "unnamed Scav";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : _guardMode(false)
{
	if (MSGS > 0)
		std::cout << "ScavTrap string constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(), _guardMode(false)
{
	if (MSGS > 0)
		std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_name = ref.getName();
	this->_hitPoints = ref.getHp();
	this->_energyPoints = ref.getEp();
	this->_attackDamage = ref.getAd();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	this->_guardMode = rhs._guardMode;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	if (MSGS > 0)
		std::cout << "ScavTrap destructor called on " << this->getName() << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getEp() > 1)
	{
		this->_energyPoints =  this->_energyPoints - 1;
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << " with great power, causing " << this->getAd() << " points of damage!" << std::endl;
	}
	else
		std::cout << "The mighty ScavTrap has no energy to spend, it can't be repaired" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_guardMode)
		std::cout << "ScavTrap " << this->getName() << " is already guarding the gate." << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " has started guarding the gate." << std::endl;
	this->_guardMode = true;
}