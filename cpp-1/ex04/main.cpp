/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:09:51 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/30 08:33:21 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	replaceLine(std::string& line, const std::string& s1, const std::string& s2) {
	size_t	startPos = 0;
	while ((startPos = line.find(s1, startPos)) != std::string::npos) {
		line.erase(startPos, s1.length());
		line.insert(startPos, s2);
		startPos += s2.length();
	}
}

int main(int ac, char **av) {
	
	if (ac != 4) {
		std::cerr << "error: too many or less arguments";
		return 1;
	}
	
	const char *file = av[1];
	std::string	s1 = av[2];
	std::string s2 = av[3];
	
	std::ifstream inFile(file);
	std::ofstream oFile("temp.txt");

	std::cout << "in " << file << " changing " << av[2] << " to " << av[3] << std::endl;

	if (s1.empty() || s2.empty()) {
		std::cerr << "invalid input";
		return 1;
	}

	if (!inFile) {
		std::cerr << "unable to open input file";
		return 1;
	}
	if (!oFile) {
		std::cerr << "unable to open output file";
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		replaceLine(line, s1, s2);
		oFile << line << '\n';
	}

	inFile.close();
	oFile.close();

	if (std::rename("temp.txt", file) != 0) {
		std::cerr << "error renaming file";
		return 1;
	}
	
	return 0;
}