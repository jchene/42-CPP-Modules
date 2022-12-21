/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:49:42 by jchene            #+#    #+#             */
/*   Updated: 2022/12/21 19:17:09 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPROTEC
# define LIBPROTEC
# include <iostream>
# include <string>
#endif
#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
private:
	T				*_start;
	unsigned int	_maxSize;

public:

	Array() : _start(NULL), _maxSize(0); {
		if (MSGS > 0)
			std::cout << "default c.tor called" << std::endl
	};

	Array(unsigned int n) : _start(NULL), _maxSize(0) {
		if (MSGS > 0)
			std::cout << "uint c.tor called" << std::endl
		this->_start = new T[n];
		if (!this->_start)
			return;
		this->_maxSize = n;
	};

	Array(const Array &ref) _start(NULL), _maxSize(0) {
		if (MSGS > 0)
			std::cout << "copy c.tor called" << std::endl
		unsigned int size = ref.size();
		this->_start = new T[size];
		if (!this->_start)
			return;
		this->_maxSize = size;
		for (unsigned int i = 0; i < this->_maxSize; i++)
		{
			(*this)[i] = ref[i];
		}
	};

	Array &operator=(const Array &ref) {
		if (MSGS > 0)
			std::cout << "o.tor = called" << std::endl
		if (this->_start)
			delete this->_start;
		unsigned int size = ref.size();
		this->_start = new T[size];
		if (!this->_start)
			return;
		this->_maxSize = size;
		for (unsigned int i = 0; i < this->_maxSize; i++)
		{
			(*this)[i] = ref[i];
		}
	};

	const Array &operator[](int index)
	{
		if (index >= 0)
			return (this->_start + index);
		throw();
	};

	~Array() {
		if (MSGS > 0)
			std::cout << "d.tor called" << std::endl;
		free(this->_start);
	};

	unsigned int size() const {
		return (this->_maxSize);
	};
};

#endif