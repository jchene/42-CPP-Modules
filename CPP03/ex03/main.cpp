/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:13 by jchene            #+#    #+#             */
/*   Updated: 2022/10/23 20:41:19 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap Clap1("Roger");
	ScavTrap Scav1("Brutus");
	FragTrap Frag1("Megatron");

	Clap1.attack(Scav1.getName());
	Scav1.takeDamage(Clap1.getAd());
	Scav1.attack(Frag1.getName());
	Frag1.takeDamage(Scav1.getAd());
	Frag1.attack(Clap1.getName());
	Clap1.takeDamage(Frag1.getAd());

	FragTrap Frag2(Frag1);

	std::cout << "Frag2 has " << Frag2.getHp() << " hit points" << std::endl;

	FragTrap Frag3;
	Frag3 = Frag2;

	std::cout << "Frag3 has " << Frag3.getHp() << " hit points" << std::endl;

	Frag1.highFivesGuys();

	return (0);
}