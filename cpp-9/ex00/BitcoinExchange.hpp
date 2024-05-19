/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:05:33 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/19 21:25:57 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange	&operator=(BitcoinExchange const &n);
		~BitcoinExchange();

		void	initialiseInternalDB(std::ifstream &internal_db);
		
		float	getValueFromDataBase(const std::string& date); ///////
		
		bool	isDateValid(std::string const &date);
		bool	isDateCorectFormat(std::string const &date);
        bool	isValueInCorrectFormat(const std::string& value); //////
	private:
		std::map<std::string, float> _database;
};
