/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:22:13 by jchene            #+#    #+#             */
/*   Updated: 2022/10/19 17:35:23 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fBits = 8;

public:
	Fixed();
	Fixed(Fixed &cpy);
	Fixed &operator=(Fixed &rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif