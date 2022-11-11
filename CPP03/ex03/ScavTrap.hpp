/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:29:24 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 20:35:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	bool _guardMode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ref);
	ScavTrap &operator=(const ScavTrap &rhs);
	virtual ~ScavTrap();

	virtual void attack(const std::string &target);
	void guardGate();
};