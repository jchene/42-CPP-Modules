/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/10/23 20:38:08 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _guardMode(false)
{
	if (MSGS > 0)
		std::cout << "ScavTrap default constructor called" << std::endl;
	this->setName("unnamed Scav");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::ScavTrap(std::string name) : _guardMode(false)
{
	if (MSGS > 0)
		std::cout << "ScavTrap string constructor called" << std::endl;
	this->setName(name);
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(), _guardMode(false)
{
	if (MSGS > 0)
		std::cout << "ScavTrap copy constructor called" << std::endl;
	this->setName(ref.getName());
	this->setHp(ref.getHp());
	this->setEp(ref.getEp());
	this->setAd(ref.getAd());
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->setName(rhs.getName());
	this->setHp(rhs.getHp());
	this->setEp(rhs.getEp());
	this->setAd(rhs.getAd());
	this->_guardMode = rhs._guardMode;
	return (*this);
}

ScavTrap::~ScavTrap() 
{
	if (MSGS > 0)
		std::cout << "ScavTrap destructor called on " << this->getName() << std::endl;
}

bool ScavTrap::isGuarding() const { return (this->_guardMode); }

void ScavTrap::attack(const std::string &target)
{
	if (this->getEp() > 1)
	{
		this->setEp(this->getEp() - 1);
		std::cout << this->getName() << " attacks " << target << " with great power, causing " << this->getAd() << " points of damage!" << std::endl;
	}
	else
		std::cout << "The mighty ScavTrap has no energy to spend, it can't be repaired" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_guardMode)
	{
		std::cout << this->getName() << " has stopped guarding the gate." << std::endl;
		this->_guardMode = false;
	}
	else
	{
		std::cout << this->getName() << " has started guarding the gate." << std::endl;
		this->_guardMode = true;
	}
}