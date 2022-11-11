/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:29:24 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 18:17:40 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _guardMode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ref);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};