/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:03:20 by jchene            #+#    #+#             */
/*   Updated: 2022/11/18 19:32:49 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(std::string const &name)
{
	if (MSGS > 0)
		std::cout << "Character default c.tor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 3; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &ref)
{
	if (MSGS > 0)
		std::cout << "Character copy c.tor called" << std::endl;
	this->_name = ref.getName();
	for (int i = 0; i < 3; i++)
	{
		if (this->_inventory[i])
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
		if (ref.getMateria(i))
			this->_inventory[i] = ref.getMateria(i)->clone();
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (MSGS > 0)
		std::cout << "Character copy assignment o.tor called" << std::endl;
	this->_name = rhs.getName();
	for (int i = 0; i < 3; i++)
	{
		if (this->_inventory[i])
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
		if (rhs.getMateria(i))
			this->_inventory[i] = rhs.getMateria(i)->clone();
	}
}

Character::~Character()
{
	if (MSGS > 0)
		std::cout << "Character d.tor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_inventory[idx]);
}

std::string const &Character::getName() const { return (this->_name); }

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->_inventory[i] && this->_inventory[i] == m)
			return;
		if (!(this->_inventory))
			this->_inventory[i] = m;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{ 
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx]->use(target);
}