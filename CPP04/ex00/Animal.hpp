/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:55 by jchene            #+#    #+#             */
/*   Updated: 2022/11/13 17:22:34 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#ifndef MSGS
#define MSGS 1
#endif

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &ref);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};