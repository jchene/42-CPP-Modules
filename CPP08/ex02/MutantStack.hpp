/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:55:22 by jchene            #+#    #+#             */
/*   Updated: 2022/12/30 01:19:09 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSGS
# define MSGS 1
#endif
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>() {};
	MutantStack<T>(const MutantStack<T> &ref)
	{
		*this = ref;
	};
	MutantStack<T> &operator=(const MutantStack<T> &ref)
	{
		(void)ref;
		return (*this);
	};
	~MutantStack<T>() {};


	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	};
	iterator end() 
	{
		return (this->c.end());
	};
};

#endif