/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:00:50 by jchene            #+#    #+#             */
/*   Updated: 2022/11/15 16:52:56 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
//#include "Acat.hpp"

int main()
{
	Animal *array[10];
	int i;
	for (i = 0; i < 5; i++)
		array[i] = new Dog();
	for (i = 0; i < 5; i++)
		array[i + 5] = new Cat();
	//array[9] = new Acat();
	for (i = 0; i < 10; i++)
		delete(array[i]);
	return 0;
}
