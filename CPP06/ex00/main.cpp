/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:34:01 by jchene            #+#    #+#             */
/*   Updated: 2022/12/11 17:32:15 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPROTEC
# define LIBPROTEC
# include <string>
# include <iostream>
#endif
#include "Convertor.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (-1);
	}
	Convertor C(argv[1]);
	return (0);
}