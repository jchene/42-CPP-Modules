/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:08:46 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 15:48:06 by jchene           ###   ########.fr       */
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
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &ref);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif