/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:34 by jchene            #+#    #+#             */
/*   Updated: 2022/11/13 17:22:38 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

class Dog : public Animal
{
protected:
public:
	Dog();
	Dog(const Dog &ref);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog();

	void makeSound() const;
};