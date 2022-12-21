/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:49:42 by jchene            #+#    #+#             */
/*   Updated: 2022/12/21 18:10:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
#endif
#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T array[], size_t length, void (*fctPtr)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		fctPtr(array[i]);
	}
}

#endif