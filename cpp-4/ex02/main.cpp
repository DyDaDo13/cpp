/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:01:01 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/01 12:23:50 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	//filled half
	int size = 100;
	const Animal* animal_array[size];
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animal_array[i] = new Dog();
		else
			animal_array[i] = new Cat();
	}
	
	//delete harray
	for (int i = 0; i < size; i++) {
		delete animal_array[i];
	}
	return 0;
}