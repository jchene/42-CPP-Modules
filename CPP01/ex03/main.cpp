/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:23:56 by jchene            #+#    #+#             */
/*   Updated: 2022/10/03 17:35:54 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name);

int main()
{
	Zombie *horde = zombieHorde(6, "Jacques");
	for (int i = 0; i < 6; i++)
		horde[i].announce();
	std::cout << "All done." << std::endl;
	delete [] horde;
	return (0);
}