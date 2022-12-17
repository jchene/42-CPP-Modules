/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:21:12 by jchene            #+#    #+#             */
/*   Updated: 2022/12/17 18:42:19 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
# include <cstdlib>
#endif
#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
	virtual ~Base() {};
};

Base *generate(void);
void identify(Base *p);
void identify(Base &ref);

#endif
