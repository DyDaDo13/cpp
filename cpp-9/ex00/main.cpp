/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:49:57 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/20 14:49:58 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int errorHandler(std::string error, int i) {
	std::cerr << error << std::endl;
	return i;
}

int main(int ac, char **av) {
	if (ac != 2)
		return errorHandler("Error: too many or less arguments", 1);

	std::ifstream input_db(av[1], std::ifstream::in);
	if (!input_db.is_open())
		return errorHandler("Error: can't open input file", 1);

	std::ifstream internal_db("./data.csv", std::ifstream::in);
	if (!internal_db.is_open())
		return errorHandler("Error: internal database not found", 1);
	
	BitcoinExchange btc;
	btc.initialiseInternalDB(internal_db);
	std::string line;
	std::getline(input_db, line);
	while (std::getline(input_db, line)) {
		size_t delim = line.find('|');
		if (delim == std::string::npos || line.length() < delim + 2) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, delim - 1);
		if (!btc.isDateCorectFormat(date) || !btc.isDateValid(date))
			continue ;
		std::string value_str = line.substr(delim + 2);
		if (!btc.isValueInCorrectFormat(value_str))
			continue ;
		float value = std::atof(value_str.c_str());
		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << value * btc.getValueFromDataBase(date) << std::endl;
	}
	internal_db.close();
	input_db.close();
	return 0;
}
