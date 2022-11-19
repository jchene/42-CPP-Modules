/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:31:18 by jchene            #+#    #+#             */
/*   Updated: 2022/11/19 19:37:24 by jchene           ###   ########.fr       */
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
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	const std::string const &getName() const;
	int const &getGrade() const;
	void promote();
	void demote();
};

#endif