/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:08 by jchene            #+#    #+#             */
/*   Updated: 2022/10/23 20:38:49 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	if (MSGS > 0)
		std::cout << "FragTrap default constructor called" << std::endl;
	this->setName("unnamed Frag");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

FragTrap::FragTrap(std::string name)
{
	if (MSGS > 0)
		std::cout << "FragTrap string constructor called" << std::endl;
	this->setName(name);
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap()
{
	if (MSGS > 0)
		std::cout << "FragTrap copy constructor called" << std::endl;
	this->setName(ref.getName());
	this->setHp(ref.getHp());
	this->setEp(ref.getEp());
	this->setAd(ref.getAd());
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (MSGS > 0)
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->setName(rhs.getName());
	this->setHp(rhs.getHp());
	this->setEp(rhs.getEp());
	this->setAd(rhs.getAd());
	return (*this);
}

FragTrap::~FragTrap() 
{
	if (MSGS > 0)
		std::cout << "FragTrap destructor called on " << this->getName() << " and it exploded!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " wants to do a high five!" << std::endl;
}
