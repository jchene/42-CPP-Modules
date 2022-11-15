/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:31 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:22:56 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
#define MSGS 1
#endif
#ifndef LIB_PROTEC
#define LIB_PROTEC
#include <string>
#include <iostream>
#endif
#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &ref);
	Brain &operator=(const Brain &rhs);
	~Brain();

	std::string getIdea(unsigned int nb) const;
};

#endif