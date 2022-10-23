/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:13 by jchene            #+#    #+#             */
/*   Updated: 2022/10/23 20:20:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap Clap1("Roger");
	ScavTrap Scav1("Brutus");

	Clap1.attack(Scav1.getName());
	Scav1.takeDamage(Clap1.getAd());
	Scav1.attack(Clap1.getName());
	Clap1.takeDamage(Scav1.getAd());

	ScavTrap Scav2(Scav1);

	std::cout << "Scav2 has " << Scav2.getHp() << " hit points" << std::endl;

	ScavTrap Scav3;
	Scav3 = Scav2;

	std::cout << "Scav3 has " << Scav3.getHp() << " hit points" << std::endl;

	Scav1.guardGate();

	return (0);
}