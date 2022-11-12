/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:13 by jchene            #+#    #+#             */
/*   Updated: 2022/11/12 19:21:10 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond1 = DiamondTrap();
	diamond1.whoAmI();

	DiamondTrap diamond2 = DiamondTrap("Roger");
	diamond2.whoAmI();

	DiamondTrap diamond3 = DiamondTrap(diamond1);
	diamond3.whoAmI();

	diamond3 = diamond2;
	diamond3.whoAmI();
	return (0);
}