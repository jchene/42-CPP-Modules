/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:03:29 by jchene            #+#    #+#             */
/*   Updated: 2022/11/17 18:08:00 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
#define MSGS 1
#endif
#ifndef LIBPROTEC
#define LIBPROTEC
#include <iostream>
#include <string>
#endif
#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &ref);
	Ice &operator=(const Ice &rhs);
	virtual ~Ice();

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif