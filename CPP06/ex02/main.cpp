/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:14:46 by jchene            #+#    #+#             */
/*   Updated: 2022/12/17 19:09:27 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *ptr;
	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
	return (0);
}