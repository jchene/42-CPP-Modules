/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Acat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:33 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:51:01 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACAT_HPP
#define ACAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class ACat : public Animal
{
private:
	Brain *_brain;

public:
	ACat();
	ACat(const ACat &ref);
	ACat &operator=(const ACat &rhs);
	virtual ~ACat();

	Brain *getBrain() const;
};

#endif