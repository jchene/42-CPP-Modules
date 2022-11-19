/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:03:18 by jchene            #+#    #+#             */
/*   Updated: 2022/11/19 17:09:14 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
protected:
	std::string _name;
	AMateria *_inventory[4];

public:
	Character(std::string const &name);
	Character(const Character &ref);
	Character &operator=(const Character &rhs);
	virtual ~Character();

	AMateria *getMateria(int idx) const;
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif