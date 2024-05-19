/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:46:44 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/19 21:39:02 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy) {*this = cpy;}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &n) {
	this->_database = n._database;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}
bool	BitcoinExchange::isDateValid(std::string const &date) {
	// int hours;
	// int minutes;
	std::string yearstr = date.substr(0, date.find('-'));
	int year = std::atoi(yearstr.c_str());
		
	std::string monthstr = date.substr(date.find('-') + 1, date.find('-', date.find('-') + 1));
	int month = std::atoi(monthstr.c_str());

	std::string daystr = date.substr(date.find('-', date.find('-') + 1) + 1, date.length());
	int day = std::atoi(daystr.c_str());

	if (year < 0 || year > 2147483647)
		return (std::cerr << "Error: bad year => " << date << std::endl, false);
	if (month < 1 || month > 12)
		return (std::cerr << "Error: bad month => " << date << std::endl, false);
	if ((day < 1 || day > 31)
		|| (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		|| (day > 28 && month == 2))
		return (std::cerr << "Error: bad day => " << date << std::endl, false);
	return true;
}

bool	BitcoinExchange::isValueInCorrectFormat(std::string const &value) {
	if (value.empty() || value.find_first_not_of("0123456789.-") != std::string::npos
	 || value.at(0) == '.' || value.find('.', value.length() - 1) != std::string::npos)
	 	return (std::cerr << "Error: invalid rate => " << std::endl, false);
	else if (value.at(0) == '-')
		return (std::cerr << "Error: not a positive number." << std::endl, false);
	else if (value.length() > 10 || (value.length() == 10 && value > "2147483647"))
		return (std::cerr << "Error: too large a number." << std::endl, false);
	return true;
}

bool	BitcoinExchange::isDateCorectFormat(std::string const &date) {
	if (date.empty())
		return false;
	if (date.find('-') == std::string::npos
	|| date.find('-', date.find('-') + 1) == std::string::npos
	|| date.find_first_not_of("0123456789.-") != std::string::npos) {
		std::cerr << "Error: bad input => \"" << date << "\"" << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::initialiseInternalDB(std::ifstream &internal_db) {
	std::string line;
	size_t delim;

	std::getline(internal_db, line);
	while (std::getline(internal_db, line)) {
		delim = line.find(',');
		std::string date = line.substr(delim + 1);
		
		this->_database[line.substr(0, delim)] = std::atof(date.c_str());
	}
	internal_db.close();
}

float	BitcoinExchange::getValueFromDataBase(std::string const &date) {
	if (this->_database.count(date) > 0)
		return this->_database.at(date);
	return (--this->_database.lower_bound(date))->second;
}
