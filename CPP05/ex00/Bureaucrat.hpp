/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:31:18 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 14:50:04 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
# define MSGS 1
#endif
#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
# include <exception>
#endif
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat
{
private:
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	const std::string &getName() const;
	int const &getGrade() const;
	void promote();
	void demote();
};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &ref);

#endif