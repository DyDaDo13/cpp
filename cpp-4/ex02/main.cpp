/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:01:01 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/01 16:33:02 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	//const AAnimal* k = new AAnimal();
	// delete k;
	delete j;//should not create a leak
	delete i;
	
	//filled half
	// int size = 100;
	// const AAnimal* animal_array[size];
	// for (int i = 0; i < size; i++) {
	// 	if (i < size / 2)
	// 		animal_array[i] = new Dog();
	// 	else
	// 		animal_array[i] = new Cat();
	// }
	
	// //delete harray
	// for (int i = 0; i < size; i++) {
	// 	delete animal_array[i];
	// }
	// return 0;
}