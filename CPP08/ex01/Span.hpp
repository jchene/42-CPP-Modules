/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:51 by jchene            #+#    #+#             */
/*   Updated: 2022/12/29 18:42:45 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
# define MSGS 1
#endif
#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>

typedef std::vector<int> intVec;

class Span
{
private:
	intVec _array;
	unsigned int _maxSize;

	class arrayFullException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class noSpanException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class notEnoughSpaceException : public std::exception
	{
	public:
		const char *what() const throw();
	};

public:
	Span(unsigned int n);
	Span(const Span &rhs);
	Span &operator=(const Span &rhs);
	~Span();

	void addNumber(int number);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template< class InputIt >
	void fillArray( InputIt first, InputIt last );

	unsigned int maxSize() const;
	const intVec &getArray() const;
};

#endif