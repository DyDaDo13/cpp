#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>

class Span {
	public:
		Span(unsigned int N) : maxSize(N) {}
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
	private:
		unsigned int		maxSize;
		std::map<int, int>	numbers;
};
