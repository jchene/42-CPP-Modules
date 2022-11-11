/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 21:09:07 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	if (MSGS > 0)
		std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "unnamed Frag";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

FragTrap::FragTrap(std::string name)
{
	if (MSGS > 0)
		std::cout << "FragTrap string constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap()
{
	if (MSGS > 0)
		std::cout << "FragTrap copy constructor called" << std::endl;
	this->_name = ref.getName();
	this->_hitPoints = ref.getHp();
	this->_energyPoints = ref.getEp();
	this->_attackDamage = ref.getAd();
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHp();
	this->_energyPoints = rhs.getEp();
	this->_attackDamage = rhs.getAd();
	return (*this);
}

FragTrap::~FragTrap() 
{
	if (MSGS > 0)
		std::cout << "FragTrap destructor called on " << this->_name << " and it exploded!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " wants to do a high five!" << std::endl;
}
