/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:31:18 by jchene            #+#    #+#             */
/*   Updated: 2022/11/20 19:38:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
#define MSGS 1
#endif
#ifndef LIBPROTEC
#define LIBPROTEC
#include <iostream>
#include <string>
#include <exception>
#endif
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
private:
	class GradeTooHighException : public std::exception
	{
		GradeTooHighException() throw();
		GradeTooHighException(const GradeTooHighException &ref) throw();
		GradeTooHighException &operator=(const GradeTooHighException &rhs) throw();
		~GradeTooHighException() throw();
		
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		GradeTooLowException() throw();
		GradeTooLowException(const GradeTooLowException &ref) throw();
		GradeTooLowException &operator=(const GradeTooLowException &rhs) throw();
		~GradeTooLowException() throw();
		
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

	std::ostream &operator<<(std::ostream &lhs) const;
	const std::string const &getName() const;
	int const &getGrade() const;
	void promote();
	void demote();
	
};

#endif