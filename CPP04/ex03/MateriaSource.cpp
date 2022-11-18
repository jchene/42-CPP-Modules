/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:25:28 by jchene            #+#    #+#             */
/*   Updated: 2022/11/18 19:36:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){}

MateriaSource::MateriaSource(const MateriaSource &ref){}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs){}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria *m){}

AMateria *MateriaSource::createMateria(std::string const &type){}