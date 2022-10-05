/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:22:29 by jchene            #+#    #+#             */
/*   Updated: 2022/10/05 16:57:46 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
		std::string _name;
		Weapon		&_weapon;

public:
		HumanA(std::string name, Weapon &weapon);
		void setWeapon(Weapon &weapon);
		void attack(void);
		~HumanA(void);
};

#endif