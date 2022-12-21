/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:49:42 by jchene            #+#    #+#             */
/*   Updated: 2022/12/21 19:40:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
# include <exception>
#endif
#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
private:
	T	*_start;
	int	_maxSize;

public:

	Array<T>(void) : _start(NULL), _maxSize(0) {
		if (MSGS > 0)
			std::cout << "default c.tor called" << std::endl;
	};

	Array<T>(unsigned int n) : _start(NULL), _maxSize(n) {
		if (MSGS > 0)
			std::cout << "uint c.tor called" << std::endl;
		if (n < 0)
			throw std::out_of_range("Index out of bonds");
		this->_start = new T[n];
	};

	Array<T>(const Array &ref) : _start(NULL), _maxSize(0) {
		if (MSGS > 0)
			std::cout << "copy c.tor called" << std::endl;
		*this = ref;
	};

	Array<T> &operator=(const Array &ref) {
		if (MSGS > 0)
			std::cout << "assignment o.tor called" << std::endl;
		if (this == &ref)
			return (*this);
		if (this->_maxSize > 0)
			delete [] this->_start;
		this->_maxSize = ref.size();
		this->_start = new T[this->_maxSize];
		for (int i = 0; i < this->_maxSize; i++)
			this->_start[i] = ref[i];
		return (*this);
	};

	T &operator[](const int index) const
	{
		if (index >= 0 && index < this->_maxSize)
			return (this->_start[index]);
		throw std::out_of_range("Index out of bonds");
	};

	~Array<T>() {
		if (MSGS > 0)
			std::cout << "d.tor called" << std::endl;
		if (this->_maxSize > 0)
			delete [] this->_start;
	};

	unsigned int size() const {
		return (this->_maxSize);
	};
};

#endif