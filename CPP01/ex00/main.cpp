/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:23:56 by jchene            #+#    #+#             */
/*   Updated: 2022/09/22 18:01:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main()
{
	Zombie *zomb1 = newZombie("heap");
	zomb1->announce();
	randomChump("stack");
	std::cout << "All done." << std::endl;
	delete zomb1;
	return (0);
}