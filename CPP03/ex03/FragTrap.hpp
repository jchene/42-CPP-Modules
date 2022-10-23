/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:29:24 by jchene            #+#    #+#             */
/*   Updated: 2022/10/24 00:46:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &ref);
	FragTrap &operator=(const FragTrap &rhs);
	virtual ~FragTrap();

	void highFivesGuys(void);
};