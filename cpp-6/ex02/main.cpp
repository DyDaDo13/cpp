/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:54:26 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 15:05:31 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

static Base	*generate() {
	switch (rand() % 3) {
		case 0:
			return (new A());
			break ;
		case 1:
			return (new B());
			break ;
		case 2:
			return (new C());
			break ;
		default:
			perror("something went wrong while tring to generate a random number");
			return NULL;
	}
}

static void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(Test))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(Test))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};


static void identify(Base &Test)
{
	while (i < 3)
	{
		void *foo = NULL;
		Base &unused = (Base &)foo;
		try
		{
			if (i == 0)
				unused = dynamic_cast<A &>(Test);
			else if (i == 1)
				unused = dynamic_cast<B &>(Test);
			else if (i == 2)
				unused = dynamic_cast<C &>(Test);
			else
				std::cout << "unknow type" << std::endl;
			(void)unused;
		}
		catch (std::exception &e)
		{
			// std::cout << e.what() << std::endl;
			i++;
			identify(Test);
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main()
{
	srand(time(NULL));
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}
