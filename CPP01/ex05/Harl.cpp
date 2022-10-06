/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:52 by jchene            #+#    #+#             */
/*   Updated: 2022/10/06 18:23:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <map>

Harl::Harl(void){
	_functionPointers[0] = &info;
	_functionPointers[1] = &debug;
	_functionPointers[2] = &warning;
	_functionPointers[3] = &error;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
			  << "I really do!"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void Harl::complain(std::string level)
{
	std::map <std::string, int> map;
	map["INFO"] = 0;
	map["DEBUG"] = 1;
	map["WARNING"] = 2;
	map["ERROR"] = 3;
	((*this)._functionPointers[1])();
}

Harl::~Harl() {}