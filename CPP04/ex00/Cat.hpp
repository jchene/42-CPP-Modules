/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:45 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 15:46:51 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
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

#endif