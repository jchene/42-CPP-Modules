/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:29:24 by jchene            #+#    #+#             */
/*   Updated: 2022/11/11 20:30:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	bool _guardMode;
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &ref);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap();

	void highFivesGuys(void);

};