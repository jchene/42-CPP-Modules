/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:22:13 by jchene            #+#    #+#             */
/*   Updated: 2022/10/11 18:15:36 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXEDHPP

class Fixed
{
private:
	int _value;
	static const int _fBits = 8;
public:
	Fixed();
	Fixed(Fixed &nb);
	Fixed &operator= (Fixed &nb);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif