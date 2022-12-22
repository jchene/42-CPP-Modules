#include "easyfind.hpp"
#include <vector>
#include <list>
#define SIZE 15

int main()
{
	int a[SIZE] = {5, 6, 7, 2, 3, 1, 9, 8, 4, 8, 6, 7, 5, 4, 12};
	std::vector<int> v(a, a + SIZE);
	std::vector<int>::iterator vlocation;
	std::list<int> l(a, a + SIZE);
	std::list<int>::iterator llocation;
	try
	{
		vlocation = easyfind(v, 12);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return -1;
	}
	std::cout << "Found value at location " << (vlocation - v.begin()) << std::endl;
	try
	{
		llocation = easyfind(l, 12);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return -1;
	}
	int pos = 0;
	for (std::list<int>::iterator it = l.begin(); it != llocation; it++)
	{
		pos++;
	}
	std::cout << "Found value at location " << pos << std::endl;
	return 0;
}