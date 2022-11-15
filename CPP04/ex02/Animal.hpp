/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:55 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:46:52 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
#define MSGS 1
#endif
#ifndef LIB_PROTEC
#define LIB_PROTEC
#include <string>
#include <iostream>
#endif
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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
	virtual void makeSound() const = 0;
};

#endif