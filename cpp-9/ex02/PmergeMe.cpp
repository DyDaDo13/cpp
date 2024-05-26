/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:31:27 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/26 19:19:28 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define MIRCOSECOND 100000

unsigned int ft_stou(const std::string& str);

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const &cpy) {*this = cpy;}

PmergeMe &PmergeMe::operator=(PmergeMe const &n) {
	if (this == &n)
		return *this;
	return *this;
}

PmergeMe::~PmergeMe(void) {}

///////////////////////////////////////////vector////////////////////////////////////////////////////////

void	printVector(std::vector<unsigned int> &vec) {
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int> mergeVec(std::vector<unsigned int> &left, std::vector<unsigned int> &right) {
	std::vector<unsigned int> result;
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty()) {
		result.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty()) {
		result.push_back(right.front());
		right.erase(right.begin());
	}
	
	return result;
}

static	std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int> &vec) {
	if (vec.size() <= 1)
		return vec;
	int mid = vec.size() / 2;
	std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
	std::vector<unsigned int> right(vec.begin() + mid, vec.end());

	left = mergeInsertVec(left);
	right = mergeInsertVec(right);

	return mergeVec(left, right);
}

void PmergeMe::sortVec(int ac, char **av) {
	std::vector<unsigned int> result;

	for (int i = 1; i < ac; i++)
		result.push_back(ft_stou(av[i]));

	std::cout << "(vector) before: ";
	printVector(result);
	std::clock_t start = std::clock();
	result = mergeInsertVec(result);
	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MIRCOSECOND;
	std::cout << "(vector) after: ";
	printVector(result);
	std::cout << "time to prosses a rage of " << ac - 1 << " elements with std::vector<unsigned int> : " << time_taken << " µs" << std::endl;
}

///////////////////////////////////////////list/////////////////////////////////////////////////////////

void	printList(std::list<unsigned int> &lst) {
	std::list<unsigned int>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::list<unsigned int> mergeList(std::list<unsigned int> &left, std::list<unsigned int> &right) {
	std::list<unsigned int> result;
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty()) {
		result.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty()) {
		result.push_back(right.front());
		right.erase(right.begin());
	}
	
	return result;
}

static	std::list<unsigned int> mergeInsertList(std::list<unsigned int> &lst) {
	if (lst.size() <= 1)
		return lst;
	
	int mid = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

	for (int i = 0; i < mid; i++) {
		left.push_back(lst.front());
		lst.pop_front();
	}
	right = lst;

	left = mergeInsertList(left);
	right = mergeInsertList(right);

	return mergeList(left, right);
}

void PmergeMe::sortList(int ac, char **av) {
	std::list<unsigned int> result;

	for (int i = 1; i < ac; i++)
		result.push_back(ft_stou(av[i]));

	std::cout << "(list) before: ";
	printList(result);
	std::clock_t start = std::clock();
	result = mergeInsertList(result);
	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MIRCOSECOND;
	std::cout << "(list) after: ";
	printList(result);
	std::cout << "time to prosses a rage of " << ac - 1 << " elements with std::list<unsigned int> : " << time_taken << " µs" << std::endl;
}


const char	*PmergeMe::PmergeMe::InvalidElementException::what() const throw() {
	return "PmergeMe exception: invalid element";
}
