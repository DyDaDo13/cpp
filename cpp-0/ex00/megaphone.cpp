#include <iostream>

int main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (av++; *av; av++)
	{
		for (int i = 0; (*av)[i]; i++)
			std::cout << (char)toupper((*av)[i]);
	}
	std::cout << std::endl;
	return 0;
}