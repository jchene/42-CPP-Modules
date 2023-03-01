#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (-1);
	}
	
	std::stack<int> pile;
	RPN(argv, pile);
	std::cout << pile.top() << std::endl;
	return (0);
}
