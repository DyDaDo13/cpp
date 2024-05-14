/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:00:14 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/14 16:21:18 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iomanip>
#include <sstream>

void printStack(MutantStack<int> mstack) {
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl << "\e[36m+--------------------+" << std::endl;
    std::cout << "|     \e[0mStack Pile\e[36m     |" << std::endl;
    std::cout << "+--------------------+" << std::endl;
    while (it != ite)
    {
        std::stringstream ss;
        ss << *it;
        std::string str = ss.str();
        std::cout << "| \e[0m" << *it << std::setw(25 - str.length()) << "\e[36m |" << std::endl;
        ++it;
    }
	std::cout << "+--------------------+\e[0m" << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top();
	printStack(mstack);
	mstack.push(1700000000);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top();
	printStack(mstack);
	mstack.push(14);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top();
	printStack(mstack);
	std::cout << "the size is " << mstack.size();
	printStack(mstack);
	std::cout << "\e[31mpop\e[0m the value: " << mstack.top();
	mstack.pop();
	printStack(mstack);
	std::cout << "the size is " << mstack.size();
	printStack(mstack);
	mstack.push(3);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top();
	printStack(mstack);
	mstack.push(5);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top();
	printStack(mstack);
	mstack.push(737);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top();
	printStack(mstack);
	//[...]
	mstack.push(0);
	std::cout << "\e[32mpushing\e[0m the value: " << mstack.top() << std::endl;
	printStack(mstack);
	std::stack<int> s(mstack);
	return 0;
}