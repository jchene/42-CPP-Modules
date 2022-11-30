/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:04:12 by jchene            #+#    #+#             */
/*   Updated: 2022/11/30 18:01:00 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#define UPR_BD 0
#define LWR_BD 1
#define ALL_BD 2
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	Form(std::string name, int sGrade, int eGrade);
	Form(const Form &ref);
	Form &operator=(const Form &rhs);
	~Form();

	const std::string &getName() const;
	bool getSign() const;
	const int &getSignGrade() const;
	const int &getExecGrade() const;

	int checkGrade(int grade, int bound);
	void beSigned(const Bureaucrat &ref);
};

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);

#endif