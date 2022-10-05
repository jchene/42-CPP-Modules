/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:23:56 by jchene            #+#    #+#             */
/*   Updated: 2022/10/05 17:14:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "str address: " << &str << std::endl;
	std::cout << "str PTR address: " << stringPTR << std::endl;
	std::cout << "str REF address: " << &stringREF << std::endl;
	std::cout << "str value: " << str << std::endl;
	std::cout << "str PTR value: " << *stringPTR << std::endl;
	std::cout << "str REF value: " << stringREF << std::endl;
	return (0);
}