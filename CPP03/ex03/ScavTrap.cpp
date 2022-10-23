/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/10/24 00:50:34 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed Scav"), _guardMode(false)
{
	if (MSGS > 0)
		std::cout << this->_name << " ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardMode(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	if (MSGS > 0)
		std::cout << this->_name << " ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref), _guardMode(false)
{
	if (MSGS > 0)
		std::cout << this->_name << " ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name =rhs.getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	this->_guardMode = rhs._guardMode;
	if (MSGS > 0)
		std::cout << this->_name << " ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() 
{
	if (MSGS > 0)
		std::cout << this->_name << " ScavTrap destructor called on " << this->getName() << std::endl;
}

bool ScavTrap::isGuarding() const { return (this->_guardMode); }

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 1)
	{
		this->_energyPoints--;
		std::cout << this->_name << " attacks " << target << " with great power, causing " << this->getAd() << " points of damage!" << std::endl;
	}
	else
		std::cout << "The mighty " << this->_name << " ScavTrap has no energy to spend, it can't be repaired" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_guardMode)
	{
		std::cout << this->_name << " has stopped guarding the gate." << std::endl;
		this->_guardMode = false;
	}
	else
	{
		std::cout << this->_name << " has started guarding the gate." << std::endl;
		this->_guardMode = true;
	}
}