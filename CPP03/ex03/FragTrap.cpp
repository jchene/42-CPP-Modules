/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/10/23 23:06:35 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed Frag")
{
	if (MSGS > 0)
		std::cout << this->_name << " FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	if (MSGS > 0)
		std::cout << this->_name << " FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	if (MSGS > 0)
		std::cout << this->_name << " FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	if (MSGS > 0)
		std::cout << this->_name << " FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap() 
{
	if (MSGS > 0)
		std::cout << this->_name << " FragTrap destructor called BOOOM!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout  << this->_name << " wants to do a high five!" << std::endl;
}
