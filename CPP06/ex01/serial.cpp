/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serial.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:50:02 by jchene            #+#    #+#             */
/*   Updated: 2022/12/17 17:20:21 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serial.hpp"

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *unserialize(uintptr_t ptrValue)
{
	return (reinterpret_cast<Data *>(ptrValue));
}