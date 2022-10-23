/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:34:13 by jchene            #+#    #+#             */
/*   Updated: 2022/10/23 20:17:17 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Clap1;
	ClapTrap Clap2("Roger");

	Clap1.attack(Clap2.getName());
	Clap2.takeDamage(Clap1.getAd());
	Clap2.attack(Clap1.getName());
	Clap1.takeDamage(Clap2.getAd());
	Clap2.attack(Clap1.getName());
	Clap1.takeDamage(Clap2.getAd());

	ClapTrap Clap3(Clap1);

	std::cout << "Clap3 has " << Clap3.getHp() << " hit points" << std::endl;

	ClapTrap Clap4;
	Clap4 = Clap3;

	std::cout << "Clap4 has " << Clap4.getHp() << " hit points" << std::endl;
	return (0);
}