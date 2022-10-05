/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:24:01 by jchene            #+#    #+#             */
/*   Updated: 2022/10/05 16:41:28 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
		std::string _type;

public:
		Weapon();
		Weapon(std::string type);
		void setType(std::string name);
		const std::string &getType(void);
		~Weapon(void);
};

#endif