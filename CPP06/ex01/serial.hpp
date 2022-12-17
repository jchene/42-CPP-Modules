/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:42:52 by jchene            #+#    #+#             */
/*   Updated: 2022/12/17 17:22:20 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
# include <stdint.h>
#endif
#ifndef SERIAL_HPP
# define SERIAL_HPP

typedef struct s_Data
{
	int nb;
}				Data;

uintptr_t serialize(Data *ptr);
Data *unserialize(uintptr_t ptrValue);

#endif