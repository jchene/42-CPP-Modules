/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 17:57:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unnamed Clap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (MSGS > 0)
		std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (MSGS > 0)
		std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) : _name(ref._name), _hitPoints(ref._hitPoints), _energyPoints(ref._energyPoints), _attackDamage(ref._attackDamage)
{
	if (MSGS > 0)
		std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	if (MSGS > 0)
		std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName() const { return (this->_name); }

unsigned int ClapTrap::getHp() const { return (this->_hitPoints); }

unsigned int ClapTrap::getEp() const { return (this->_energyPoints); }

unsigned int ClapTrap::getAd() const { return (this->_attackDamage); }

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 1)
	{
		this->_energyPoints = this->_energyPoints - 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap has no energy to spend, it can't be repaired" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and has now !" << this->_hitPoints << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 1)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself for " << amount << " hit points and has now " << this->_hitPoints << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap has no energy to spend, it can't be repaired" << std::endl;
}