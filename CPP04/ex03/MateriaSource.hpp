/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:25:33 by jchene            #+#    #+#             */
/*   Updated: 2022/11/19 19:08:35 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
	AMateria *_sourceInventory[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &ref);
	MateriaSource &operator=(const MateriaSource &rhs);
	virtual ~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
	AMateria *getMateria(int idx) const;
};

#endif