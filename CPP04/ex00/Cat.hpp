/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:45 by jchene            #+#    #+#             */
/*   Updated: 2022/11/13 17:22:41 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal
{
protected:
public:
	Cat();
	Cat(const Cat &ref);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat();

	void makeSound() const;
};