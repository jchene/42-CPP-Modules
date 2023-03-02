#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int>	vec;
	std::list<int>		lst;
	double				vecTime = 0.0;	
	double				lstTime = 0.0;	

	if (fillContainers(vec, lst, argc, argv) == -1)
		return(-1);
	displayPreview(vec, 'b');
	if (argc > 2)
	{
		sortVector(vec, vecTime);
		sortList(lst, lstTime);
	}
	displayPreview(vec, 'a');
	displayTimes(vec, lst, vecTime, lstTime);
	return (0);
}
