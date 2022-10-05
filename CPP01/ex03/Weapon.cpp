/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:06:21 by jchene            #+#    #+#             */
/*   Updated: 2022/10/05 17:09:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("hands") {}

Weapon::Weapon(std::string type) : _type(type) {}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string &Weapon::getType(void)
{
	return (this->_type);
}

Weapon::~Weapon(void) {}