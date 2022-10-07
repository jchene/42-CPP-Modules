/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:50 by jchene            #+#    #+#             */
/*   Updated: 2022/10/07 17:02:27 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Harl
{
private:
	void info(void);
	void debug(void);
	void warning(void);
	void error(void);

	void badComplain(void);

public:
	Harl(void);
	void complain(std::string level);
	~Harl();
};