/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:01:01 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 11:33:52 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "\n-------------------------------------------\n" << std::endl;

const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << "\n-------------------------------------------\n" << std::endl;

std::cout << "the type fo the dog is " << j->getType() << " " << std::endl;
std::cout << "the type fo the cat is " << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << "\n-------------------------------------------\n" << std::endl;

delete meta;
delete i;
delete j;

std::cout << "\n-------------------------------------------\n" << std::endl;

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* wrongcat = new WrongCat();

std::cout << "\n-------------------------------------------\n" << std::endl;

std::cout << meta2->getType() << " " << std::endl;
std::cout << wrongcat->getType() << " " << std::endl;
wrongcat->makeSound();
meta2->makeSound();

std::cout << "\n-------------------------------------------\n" << std::endl;

delete meta2;
delete wrongcat;

return 0;
}