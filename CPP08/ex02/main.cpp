/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:55:03 by jchene            #+#    #+#             */
/*   Updated: 2022/12/30 01:29:09 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void stackTest()
{
	std::list<int> vstack;
	vstack.push_back(5);
	vstack.push_back(17);
	std::cout << vstack.back() << std::endl;
	vstack.pop_back();
	std::cout << vstack.size() << std::endl;
	vstack.push_back(3);
	vstack.push_back(5);
	vstack.push_back(737);
	vstack.push_back(0);
	std::list<int>::iterator it = vstack.begin();
	std::list<int>::iterator ite = vstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void mstackTest()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
	stackTest();
	std::cout << "----------" << std::endl;
	mstackTest();
	return 0;
}