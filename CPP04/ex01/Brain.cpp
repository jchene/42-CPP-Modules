/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:34 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:41:51 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	if (MSGS > 0)
		std::cout << "Brain default c.tor called" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	if (MSGS > 0)
		std::cout << "Brain copy c.tor called" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = ref.getIdea(i);
}

Brain &Brain::operator=(const Brain &rhs)
{
	if (MSGS > 0)
		std::cout << "Brain copy assignment o.tor called" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = rhs.getIdea(i);
	return (*this);
}

Brain::~Brain()
{
	if (MSGS > 0)
		std::cout << "Brain d.tor called" << std::endl;
}

std::string Brain::getIdea(unsigned int nb) const
{
	if (nb < 100)
		return (this->ideas[nb]);
	return ("");
}