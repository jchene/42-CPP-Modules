#include "RPN.hpp"

int RPN(char **argv, std::stack<int> &pile)
{
	std::stringstream stringStream;
	int op1;
	int op2;
	for (char *c = &argv[1][0]; *c != '\0'; c++)
	{
		if (*c == ' ')
			continue;
		if (*c >= '0' && *c <= '9')
		{
			pile.push(*c - '0');
			continue;
		}
		op2 = pile.top();
		pile.pop();
		op1 = pile.top();
		pile.pop();
		switch (*c)
		{
		case '+':
			pile.push(op1 + op2);
			break;
		case '-':
			pile.push(op1 - op2);
			break;
		case '*':
			pile.push(op1 * op2);
			break;
		case '/':
			if (op2 == 0)
			{
				std::cout << "Division by 0" << std::endl;
				return (-1);
			}
			pile.push(op1 / op2);
			break;
		default:
			pile.push(op2);
			pile.push(op1);
			std::cout << "Bad symbol" << std::endl;
			return (-1);
		}
	}
	return (0);
}