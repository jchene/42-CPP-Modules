/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:00:21 by jchene            #+#    #+#             */
/*   Updated: 2022/10/07 16:23:04 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl test;
	std::string level;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (-1);
	}
	level = argv[1];
	test.complain(level);
	return (0);
}