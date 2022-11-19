/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:25:28 by jchene            #+#    #+#             */
/*   Updated: 2022/11/19 19:08:36 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (MSGS > 0)
		std::cout << "Materia Source default c.tor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_sourceInventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	if (MSGS > 0)
		std::cout << "Materia Source copy c.tor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_sourceInventory[i] != NULL)
		{
			delete (this->_sourceInventory[i]);
			this->_sourceInventory[i] = NULL;
		}
		this->_sourceInventory[i] = ref.getMateria(i)->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (MSGS > 0)
		std::cout << "Materia Source copy assignment o.tor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_sourceInventory[i] != NULL)
		{
			delete (this->_sourceInventory[i]);
			this->_sourceInventory[i] = NULL;
		}
		this->_sourceInventory[i] = rhs.getMateria(i)->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	if (MSGS > 0)
		std::cout << "Materia Source d.tor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_sourceInventory[i] == NULL)
			continue;
		for (int j = 0; j < 4; j++)
		{
			if (i != j && this->_sourceInventory[j] == this->_sourceInventory[i])
				this->_sourceInventory[j] = NULL;
		}
		delete (this->_sourceInventory[i]);
		this->_sourceInventory[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_sourceInventory[i]))
		{
			this->_sourceInventory[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_sourceInventory[i] && !(this->_sourceInventory[i]->getType().compare(type)))
			return(this->_sourceInventory[i]->clone());
	}
	return (NULL);
}

AMateria *MateriaSource::getMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_sourceInventory[idx]);
}
