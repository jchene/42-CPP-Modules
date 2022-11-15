/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:40 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 15:21:00 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	if (MSGS > 0)
		std::cout << "WrongCat default c.tor called" << std::endl;
	this->_type = "Cat";
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal()
{
	if (MSGS > 0)
		std::cout << "WrongCat copy c.tor called" << std::endl;
	this->_type = ref.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (MSGS > 0)
		std::cout << "WrongCat copy assignment o.tor called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	if (MSGS > 0)
		std::cout << "WrongCat default d.tor called" << std::endl;
}