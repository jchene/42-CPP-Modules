/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:42:23 by jchene            #+#    #+#             */
/*   Updated: 2022/12/17 17:19:38 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serial.hpp"

int main(void)
{
	Data myStruc;
	myStruc.nb = 42;
	std::cout << "Struc addr: " << &myStruc << " - nb: " << myStruc.nb << std::endl;

	uintptr_t ptrValue;
	ptrValue = serialize(&myStruc);

	Data *strucPtr;
	strucPtr = unserialize(ptrValue);
	std::cout << "Struc addr: " << strucPtr << " - nb: " << strucPtr->nb << std::endl;
	return (0);
}