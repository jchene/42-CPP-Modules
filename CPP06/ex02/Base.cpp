/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:11:48 by jchene            #+#    #+#             */
/*   Updated: 2022/12/17 19:11:07 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class A;
class B;
class C;

Base *generate(void)
{
	int nb = rand() % 3;
	switch (nb)
	{
	case (0):
		return new A();
		break;
	case (1):
		return new B();
		break;
	case (2):
		return new C();
		break;
	default:
		return NULL;
		break;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A identified from pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B identified from pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C identified from pointer" << std::endl;
}

void identify(Base &ref)
{
	try
	{
		A &a = dynamic_cast<A &>(ref);
		std::cout << "A identified from pointer" << std::endl;
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(ref);
		std::cout << "B identified from pointer" << std::endl;
		(void)b;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(ref);
		std::cout << "C identified from pointer" << std::endl;
		(void)c;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}