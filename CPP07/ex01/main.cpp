#include "iter.hpp"

template <typename T>
void increment(T &v1)
{
	v1++;
}

template <typename T>
void displayArray(T array[], size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << "array[" << i << "]: " << array[i] << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	int array[] = {0, 1, 2, 3};
	displayArray(array, 4);
	iter(array, 4, increment);
	displayArray(array, 4);
	return 0;
}