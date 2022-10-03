/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:23:56 by jchene            #+#    #+#             */
/*   Updated: 2022/10/03 17:41:07 by jchene           ###   ########.fr       */
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
	std::cout << "str address: " << str << std::endl;
	std::cout << "str PTR address: " << *stringPTR << std::endl;
	std::cout << "str REF address: " << stringREF << std::endl;
	return (0);
}