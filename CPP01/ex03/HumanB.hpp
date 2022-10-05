/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:20 by jchene            #+#    #+#             */
/*   Updated: 2022/10/05 16:54:45 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
		std::string _name;
		Weapon		*_weapon;

public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void);
		~HumanB(void);
};

#endif